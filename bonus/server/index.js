#!/usr/bin/env node
const WebSocketServer = require("websocket").server;
const http = require("http");
const { wsRequest } = require("./ws/request");

const server = http.createServer(function (request, response) {
	console.log(new Date() + " Received request for " + request.url);
	response.writeHead(404);
	response.end();
});
server.listen(8000, function () {
	console.log(new Date() + " Server is listening on port 8000");
});

wsServer = new WebSocketServer({
	httpServer: server,
	autoAcceptConnections: false,
});

wsServer.on("request", wsRequest);
