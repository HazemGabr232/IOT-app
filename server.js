const express = require('express');
const SocketServer = require('ws').Server;
const path = require('path');

const PORT = process.env.PORT || 9000;
const INDEX = path.join(__dirname, '/pages/index.html');

const server = express()
	.use(express.static(path.join(__dirname, "pages")))
	.use('/',(req, res) =>{	res.sendFile(INDEX) })
	.listen(PORT, () => console.log(`Listening on ${ PORT }`))

const socetServer = new SocketServer({ server });
var count = 0;
socetServer.on('connection', (socketClient) => {
	console.log('Client connected');	
	count++
	socketClient.send("hello client" + count);

	socketClient.on('message', function(msg) {
		socetServer.clients.forEach(function(c){
			if(msg =="client"){
				socketClient.type = "browser"
			}
			else if(msg =="hardware"){
				socketClient.type = "hardware"
			}
			
			
			else if(msg =="on1"){
				socketClient.type = "browser"
			}
			else if(msg =="off1"){
				socketClient.type = "browser"
			}
			else if(msg =="on2"){
				socketClient.type = "browser"
			}
			else if(msg =="off2"){
				socketClient.type = "browser"
			}
			else if(msg =="on3"){
				socketClient.type = "browser"
			}
			else if(msg =="off3"){
				socketClient.type = "browser"
			}
			
			
			else {
				c.send(msg);
			}
			
		});
		console.log(msg);
		
	});
	
	socketClient.on('close', () => console.log('Client disconnected'));
});
