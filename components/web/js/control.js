var g1, g2, g3, g4, g5, g6;
window.onload = function(){
	if(document.getElementById('g1'))
		g1 = new JustGage({
			id: "g1", 
			min: -30,
			max: 30,
			title: "Time",
			label: "seconds",  
			showMinMax: false,
			gaugeColor: "#fff",
			levelColors: ["#000"],
			showInnerShadow: false,        
			startAnimationTime: 1,
			startAnimationType: "linear",
			refreshAnimationTime: 1,
			refreshAnimationType: "linear",
			//gaugeWidthScale: 0.2            
		  });
		
	if(document.getElementById('g2'))
		g2 = new JustGage({
			id: "g2", 
			min: -30,
			max: 30,
			title: "Time",
			label: "seconds",  
			showMinMax: false,
			gaugeColor: "#fff",
			levelColors: ["#000"],
			showInnerShadow: false,        
			startAnimationTime: 1,
			startAnimationType: "linear",
			refreshAnimationTime: 1,
			refreshAnimationType: "linear",
			//gaugeWidthScale: 0.2            
		  });
		
	if(document.getElementById('g3'))
		g3 = new JustGage({
			id: "g3", 
			min: -30,
			max: 30,
			title: "Time",
			label: "seconds",  
			showMinMax: false,
			gaugeColor: "#fff",
			levelColors: ["#000"],
			showInnerShadow: false,        
			startAnimationTime: 1,
			startAnimationType: "linear",
			refreshAnimationTime: 1,
			refreshAnimationType: "linear",
			//gaugeWidthScale: 0.2            
		  });
	if(document.getElementById('g4'))
		g4 = new JustGage({
			id: "g4", 
			min: -30,
			max: 30,
			title: "Time",
			label: "seconds",  
			showMinMax: false,
			gaugeColor: "#fff",
			levelColors: ["#000"],
			showInnerShadow: false,        
			startAnimationTime: 1,
			startAnimationType: "linear",
			refreshAnimationTime: 1,
			refreshAnimationType: "linear",
			//gaugeWidthScale: 0.2            
		  });
	
};

var socket = io.connect('http://192.168.1.109');
socket.on('serverStatus', function (data) {
	console.log(data);
	displayStatus(data);
});
socket.on('sequenceState', function (data) {
	console.log(data);
	if(data == 'initialized')
		document.bgColor="white";
	if(data == 'stop')
		document.bgColor="white";
	displayStatus(data);
});
socket.on('time', function (data) {
	if(g1)
		g1.refresh(parseFloat(data));
	if(g2)
		g2.refresh(parseFloat(data));
	if(g3)
		g3.refresh(parseFloat(data));
	if(g4)
		g4.refresh(parseFloat(data));
	if(g5)
		g5.refresh(parseFloat(data));
	if(g6)
		g6.refresh(parseFloat(data));
		
	if(data >= 0) {
		data = "+"+data;
	}
	document.getElementById('time').value = ('T'+data);
});

function run() {
    socket.emit('controlState', 'initiate');
}
function stop() {
    socket.emit('controlState', 'stop');
	document.getElementById('time').value = "";
}

function clearStatus() {
    document.getElementById('status').value = "";
}

function displayStatus(data){
	document.getElementById('status').value = document.getElementById('status').value + data + '\n';
	document.getElementById('status').scrollTop = document.getElementById('status').scrollHeight;
}