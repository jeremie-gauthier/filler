const readline = require("readline");

function timeout(ms) {
	return new Promise((resolve) => setTimeout(resolve, ms));
}

async function processLineByLine() {
	const rl = readline.createInterface({
		input: process.stdin,
		crlfDelay: Infinity,
	});

	let height = 0;
	let boardGame = [];
	for await (const line of rl) {
		if (line.includes("Plateau")) {
			height = parseInt(line.split(" ")[1]);
			boardGame = [];
		} else if (height > 0) {
			let row = line.split(" ")[1];
			if (row !== "") {
				boardGame.push(row);
				height--;
				if (height === 0) {
					boardToString = boardGame.join(",");
					console.log(boardToString);
				}
			}
		}
		await timeout(1);
	}
}

processLineByLine();
