import React, { useState, useEffect, useRef } from "react";
import {
	Container,
	Typography,
	FormControl,
	InputLabel,
	MenuItem,
	Select,
	Button,
	LinearProgress,
} from "@material-ui/core";
import {
	makeStyles,
	createMuiTheme,
	ThemeProvider,
} from "@material-ui/core/styles";
import { w3cwebsocket as W3CWebSocket } from "websocket";

const HEIGHT = 480;
const WIDTH = 800;
const SIZE_TILE = 20;
const BORDER_SIZE = 1;
const TOTAL_TILES = 960;

function grid(ctx) {
	ctx.strokeStyle = "white";
	ctx.lineWidth = 1;
	ctx.beginPath();
	for (let x = SIZE_TILE; x < WIDTH; x += SIZE_TILE) {
		ctx.moveTo(x, 0);
		ctx.lineTo(x, HEIGHT);
	}
	for (let y = SIZE_TILE; y < HEIGHT; y += SIZE_TILE) {
		ctx.moveTo(0, y);
		ctx.lineTo(WIDTH, y);
	}
	ctx.stroke();
}

function wipe(ctx) {
	ctx.fillStyle = "lightgrey";
	ctx.fillRect(0, 0, WIDTH, HEIGHT);
	grid(ctx);
}

function fill(ctx, locations, playerColor) {
	ctx.fillStyle = playerColor;
	locations.map((location) =>
		ctx.fillRect(
			location.x * SIZE_TILE,
			location.y * SIZE_TILE,
			SIZE_TILE - BORDER_SIZE,
			SIZE_TILE - BORDER_SIZE
		)
	);
}

function App() {
	const classes = useStyles(theme);

	const canvasRef = useRef(null);
	const [ctx, setCtx] = useState(null);
	useEffect(() => {
		if (!ctx) {
			const canvas = canvasRef.current;
			setCtx(canvas.getContext("2d"));
		}
		if (ctx) {
			grid(ctx);
		}
	}, [ctx]);

	const [gameState, setGameState] = useState(false);
	const [player1, setPlayer1] = useState("");
	const [player2, setPlayer2] = useState("");

	const [scores, setScores] = useState({ p1: 0, p2: 0 });

	function arrcpy(board) {
		const p1 = [];
		let scorep1 = 0;
		const p2 = [];
		let scorep2 = 0;

		board.forEach((row, idx_row) => {
			Array.from(row).forEach((col, idx_col) => {
				if (col === "o" || col === "O") {
					p1.push({ y: idx_row, x: idx_col });
					scorep1++;
				} else if (col === "x" || col === "X") {
					p2.push({ y: idx_row, x: idx_col });
					scorep2++;
				}
			});
		});

		const canvas = canvasRef.current;
		const context = canvas.getContext("2d");
		fill(context, p1, theme.palette.primary.main);
		fill(context, p2, theme.palette.secondary.main);
		return [scorep1, scorep2];
	}

	const [connection, setConnection] = useState(null);
	useEffect(() => {
		const wsConn = new W3CWebSocket("ws://86.247.50.28:8000");
		setConnection(wsConn);

		return () => {
			wsConn.close();
		};
	}, [setConnection]);

	const handleSubmit = () => {
		if (
			connection.readyState === connection.OPEN &&
			player1 !== "" &&
			player2 !== ""
		) {
			setGameState(true);
			if (!connection.onmessage) {
				connection.onmessage = ({ data }) => {
					const msg = JSON.parse(data);

					if ("board" in msg) {
						const [scorep1, scorep2] = arrcpy(msg.board);
						setScores({ p1: scorep1, p2: scorep2 });
						setGameState(false);
					} else if ("msg" in msg && msg.msg === "EXIT") {
						setGameState(false);
					}
				};
			}

			const message = JSON.stringify({ p1: player1, p2: player2 });
			connection.send(message);
		}
	};

	return (
		<ThemeProvider theme={theme}>
			<Container maxWidth="md">
				<Typography color={"primary"} variant="h2">
					Filler
				</Typography>
				<Typography color={"secondary"} variant="h6">
					AIs fighting to gain the control of a board game
				</Typography>
				<Container className={classes.main} maxWidth="md">
					<Container className={classes.controls} maxWidth="sm">
						<div className={classes.inline}>
							<FormControl className={classes.formControl}>
								<InputLabel id="select-player1" className={classes.player1}>
									Player 1
								</InputLabel>
								<Select
									disabled={gameState === true}
									labelId="select-player1"
									value={player1}
									id="input-player1"
									onChange={(e) => setPlayer1(e.target.value)}
									color={"primary"}
								>
									<MenuItem className={classes.player1} value={"abanlin"}>
										Abanlin
									</MenuItem>
									<MenuItem className={classes.player1} value={"carli"}>
										Carli
									</MenuItem>
									<MenuItem className={classes.player1} value={"champely"}>
										Champely
									</MenuItem>
									<MenuItem className={classes.player1} value={"grati"}>
										Grati
									</MenuItem>
									<MenuItem className={classes.player1} value={"hcao"}>
										Hcao
									</MenuItem>
									<MenuItem className={classes.player1} value={"superjeannot"}>
										SuperJeannot
									</MenuItem>
									<MenuItem className={classes.player1} value={"jergauth"}>
										Jergauth
									</MenuItem>
								</Select>
							</FormControl>
							<FormControl className={classes.formControl}>
								<InputLabel id="select-player2" className={classes.player2}>
									Player 2
								</InputLabel>
								<Select
									disabled={gameState === true}
									labelId="select-player2"
									id="input-player2"
									value={player2}
									onChange={(e) => setPlayer2(e.target.value)}
									color={"primary"}
								>
									<MenuItem className={classes.player2} value={"abanlin"}>
										Abanlin
									</MenuItem>
									<MenuItem className={classes.player2} value={"carli"}>
										Carli
									</MenuItem>
									<MenuItem className={classes.player2} value={"champely"}>
										Champely
									</MenuItem>
									<MenuItem className={classes.player2} value={"grati"}>
										Grati
									</MenuItem>
									<MenuItem className={classes.player2} value={"hcao"}>
										Hcao
									</MenuItem>
									<MenuItem className={classes.player2} value={"superjeannot"}>
										SuperJeannot
									</MenuItem>
									<MenuItem className={classes.player2} value={"jergauth"}>
										Jergauth
									</MenuItem>
								</Select>
							</FormControl>
						</div>

						<Button
							disabled={player1 === "" || player2 === "" || gameState === true}
							fullWidth
							variant="contained"
							className={classes.button}
							color={"primary"}
							onClick={handleSubmit}
						>
							Start
						</Button>
						<Button
							disabled={gameState === true}
							fullWidth
							variant="contained"
							className={classes.button}
							color={"secondary"}
							onClick={() => {
								wipe(ctx);
								setScores({ p1: 0, p2: 0 });
							}}
						>
							Reset
						</Button>
					</Container>
					<LinearProgress
						variant="determinate"
						value={(scores.p1 / TOTAL_TILES) * 100}
						color="primary"
						className={classes.progressBar}
					/>
					<LinearProgress
						variant="determinate"
						value={(scores.p2 / TOTAL_TILES) * 100}
						color="secondary"
						className={classes.progressBar}
					/>
					<canvas
						ref={canvasRef}
						height={HEIGHT}
						width={WIDTH}
						className={classes.canvas}
					></canvas>
				</Container>
			</Container>
		</ThemeProvider>
	);
}

const theme = createMuiTheme({
	palette: {
		primary: {
			light: "#4dabf5",
			main: "#2196f3",
			dark: "#1769aa",
			contrastText: "#fff",
		},
		secondary: {
			light: "#ffa733",
			main: "#ff9100",
			dark: "#b26500",
			contrastText: "#000",
		},
	},
});

const useStyles = makeStyles((th) => ({
	formControl: {
		margin: theme.spacing(1),
		minWidth: 120,
	},
	selectEmpty: {
		marginTop: theme.spacing(2),
	},
	main: {
		textAlign: "center",
		marginBottom: "1rem",
	},
	controls: {
		marginTop: ".5rem",
		marginBottom: "1rem",
	},
	inline: {
		display: "flex",
		flexDirection: "row",
		justifyContent: "space-evenly",
	},
	player1: {
		color: theme.palette.primary.main,
	},
	player2: {
		color: theme.palette.secondary.main,
	},
	progressBar: {
		height: "1rem",
		width: "802px",
		marginLeft: "auto",
		marginRight: "auto",
		borderRadius: ".15rem",
	},
	button: {
		fontWeight: "bold",
	},
	canvas: {
		backgroundColor: "lightgrey",
		border: "1px solid black",
	},
}));

export default App;
