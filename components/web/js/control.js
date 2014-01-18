var socket = io.connect('http://192.168.1.109');
socket.on('serverStatus', function (data) {
	console.log(data);
	displayStatus(data);
});
socket.on('sequenceState', function (data) {
	console.log(data);
	if(data == 'initialized')
		document.bgColor="red";
	if(data == 'stop')
		document.bgColor="white";
	displayStatus(data);
});
	socket.on('time', function (data) {
	document.getElementById('time').value = ('T'+data);
});

function run() {
    socket.emit('controlState', 'initiate');
}
function stop() {
    socket.emit('controlState', 'stop');
}

function clearStatus() {
    document.getElementById('status').value = "";
}

function displayStatus(data){
	document.getElementById('status').value = document.getElementById('status').value + data + '\n';
	document.getElementById('status').scrollTop = document.getElementById('status').scrollHeight;
}