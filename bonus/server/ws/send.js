const asyncStringified = async (data) => {
	return new Promise((resolve) => {
		resolve(JSON.stringify(data));
	});
};

export const sendData = async (data, userID) => {
	const stringifiedData = await asyncStringified(data);
	clients[userID].sendUTF(stringifiedData);
};

export const sendError = (error, userID) => {
	const stringifiedData = JSON.stringify({ action: "requestError", error });
	clients[userID].sendUTF(stringifiedData);
};
