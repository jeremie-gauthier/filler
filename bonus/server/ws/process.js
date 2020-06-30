const { spawn } = require("child_process");

let END_GAME = true;

const events = {
	ERROR: "error",
	CLOSE: "close",
	DATA: "data",
	EXIT: "exit",
};

const asyncStringified = async (data) => {
	return new Promise((resolve) => {
		resolve(JSON.stringify(data));
	});
};

module.exports = {
	startFiller: (connection, args) => {
		END_GAME = false;

		const filler = spawn(
			"./filler_vm",
			[
				"-f",
				"./maps/map01",
				"-p1",
				`./champions/${args.p1}.filler`,
				"-p2",
				`./champions/${args.p2}.filler`,
			],
			{ cwd: "/home/jergauth/Documents/ecole/algo/filler/ressources-linux" }
		);
		const helper = spawn("node", ["./helper_CToNode.js"], {
			cwd: "/home/jergauth/Documents/ecole/algo/filler/bonus",
		});

		filler.on(events.ERROR, async (err) => {
			const stringifiedData = await asyncStringified(err);
			connection.sendUTF(stringifiedData);
		});

		filler.stdout.pipe(helper.stdin);

		helper.stdout.on(events.DATA, (data) => {
			const dataToString = data.toString();
			const cleanDataToString = dataToString.slice(0, -1);
			const multiData = cleanDataToString.split("\n");
			for (mdata of multiData) {
				const formatData = JSON.stringify({ board: mdata.split(",") });
				connection.sendUTF(formatData);
			}
		});

		helper.on(events.EXIT, async () => {
			END_GAME = true;
			console.log("/!\\ EXIT /!\\");
			const stringifiedData = await asyncStringified({ msg: "EXIT" });
			connection.sendUTF(stringifiedData);
		});
	},
};