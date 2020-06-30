const { startFiller } = require("./process");

const clients = {};

const getUniqueID = () => {
	const s4 = () =>
		Math.floor((1 + Math.random()) * 0x10000)
			.toString(16)
			.substring(1);
	return s4() + s4() + "-" + s4();
};

const addClient = (userID, connection) => {
	clients[userID] = connection;
};

const connectClient = (request) => {
	const userID = getUniqueID();

	// You can rewrite this part of the code to accept only the requests from allowed origin
	const connection = request.accept(null, request.origin);

	addClient(userID, connection);

	console.log(
		"connected: " + userID + " in " + Object.getOwnPropertyNames(clients)
	);
	return [connection, userID];
};

function originIsAllowed(origin) {
	return (
		origin === "http://localhost:3000" || origin === "http://86.247.50.28/"
	);
}
module.exports = {
	wsRequest: (request) => {
		if (!originIsAllowed(request.origin)) {
			request.reject();
			console.log(
				new Date() + " Connection from origin " + request.origin + " rejected."
			);
			return;
		}

		const [connection, userID] = connectClient(request);
		console.log(new Date() + " Connection accepted.");

		connection.on("message", function (message) {
			if (message.type === "utf8") {
				try {
					console.log("Received Message: " + message.utf8Data);
					const data = JSON.parse(message.utf8Data);
					console.log(data);
					startFiller(connection, data);
				} catch (err) {
					const error = JSON.stringify(err);
					connection.sendUTF(error);
				}
			}
		});

		connection.on("close", function (reasonCode, description) {
			console.log(
				new Date() + " Peer " + connection.remoteAddress + " disconnected."
			);
			delete clients[userID];
		});
	},
};
