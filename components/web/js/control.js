var gauge = new Array();
window.onload = function(){
	if(document.getElementById('g0'))
		gauge[0] = new JustGage({
			id: "g0", 
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
			gaugeWidthScale: 0.5
		  });
		
	if(document.getElementById('g1'))
		gauge[1] = new JustGage({
			id: "g1", 
			min: -30,
			max: 30,
			title: "s0",
			label: "units",  
			showMinMax: false,
			gaugeColor: "#fff",
			levelColors: ["#000"],
			showInnerShadow: false,        
			startAnimationTime: 1,
			startAnimationType: "linear",
			refreshAnimationTime: 1,
			refreshAnimationType: "linear",
			gaugeWidthScale: 0.5     
		  });
		
	if(document.getElementById('g2'))
		gauge[2] = new JustGage({
			id: "g2", 
			min: -30,
			max: 30,
			title: "s1",
			label: "units",  
			showMinMax: false,
			gaugeColor: "#fff",
			levelColors: ["#000"],
			showInnerShadow: false,        
			startAnimationTime: 1,
			startAnimationType: "linear",
			refreshAnimationTime: 1,
			refreshAnimationType: "linear",
			gaugeWidthScale: 0.5   
		  });
	if(document.getElementById('g3'))
		gauge[3] = new JustGage({
			id: "g3", 
			min: -30,
			max: 30,
			title: "s2",
			label: "units",  
			showMinMax: false,
			gaugeColor: "#fff",
			levelColors: ["#000"],
			showInnerShadow: false,        
			startAnimationTime: 1,
			startAnimationType: "linear",
			refreshAnimationTime: 1,
			refreshAnimationType: "linear",
			gaugeWidthScale: 0.5      
		  });
	if(document.getElementById('g4'))
		gauge[4] = new JustGage({
			id: "g4", 
			min: -30,
			max: 30,
			title: "s3",
			label: "units",  
			showMinMax: false,
			gaugeColor: "#fff",
			levelColors: ["#000"],
			showInnerShadow: false,        
			startAnimationTime: 1,
			startAnimationType: "linear",
			refreshAnimationTime: 1,
			refreshAnimationType: "linear",
			gaugeWidthScale: 0.5      
		  });
	if(document.getElementById('g5'))
		gauge[5] = new JustGage({
			id: "g5", 
			min: -30,
			max: 30,
			title: "s4",
			label: "units",  
			showMinMax: false,
			gaugeColor: "#fff",
			levelColors: ["#000"],
			showInnerShadow: false,        
			startAnimationTime: 1,
			startAnimationType: "linear",
			refreshAnimationTime: 1,
			refreshAnimationType: "linear",
			gaugeWidthScale: 0.5
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
	if(gauge[0])
		gauge[0].refresh(parseFloat(data));
	if(data >= 0) {
		data = "+" + data;
	}
	document.getElementById('time').value = ('T'+data);
});
socket.on('sensor', function(data) {
	var id = parseInt(data.substring(0, data.indexOf(':'))) + 1;
	data = parseFloat(data.substring(data.indexOf(':') + 1, data.length));
	if(gauge[id])
		gauge[id].refresh(data);
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