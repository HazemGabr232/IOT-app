const express = require('express');
const SocketServer = require('ws').Server;
const path = require('path');

const PORT = process.env.PORT || 80;
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
			if(msg =="client"){
				socketClient.type = "browser"
			}
			else if(msg =="hardware"){
				socketClient.type = "hardware"
			}
			else{
			socetServer.clients.forEach(function(c){			
			if(msg =="on1"){
				
				if (c.type == "hardware"){
					c.send(msg);}
				}
			else if(msg =="off1"){
				if (c.type == "hardware"){
					c.send(msg);}
				}
			else if(msg =="on2"){
				if (c.type == "hardware"){
					c.send(msg);}
				}
			else if(msg =="off2"){
				if (c.type == "hardware"){
					c.send(msg);}
				}
			else if(msg =="on3"){
				if (c.type == "hardware"){
					c.send(msg);}
				}
			else if(msg =="off3"){
				if (c.type == "hardware"){
					c.send(msg);}
				}
			
			
			else {
				c.send(msg);
			      }
		        }	
		});
		console.log(msg);
		
	});
	
	socketClient.on('close', () => console.log('Client disconnected'));
});
