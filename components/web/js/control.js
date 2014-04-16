var gauge = new Array();
var lights = new Array(0, 0, 0, 0, 0, 0, 0, 0);

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
			min: 0,
			max: 50,
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
		
	if(document.getElementById('g2'))
		gauge[2] = new JustGage({
			id: "g2", 
			min: 0,
			max: 50,
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
	if(document.getElementById('g3'))
		gauge[3] = new JustGage({
			id: "g3", 
			min: 0,
			max: 50,
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
	if(document.getElementById('g4'))
		gauge[4] = new JustGage({
			id: "g4", 
			min: 0,
			max: 50,
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
	if(document.getElementById('g5'))
		gauge[5] = new JustGage({
			id: "g5", 
			min: 0,
			max: 50,
			title: "s5",
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
	if(document.getElementById('g6'))
		gauge[6] = new JustGage({
			id: "g6", 
			min: 0,
			max: 50,
			title: "s6",
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
	if(document.getElementById('g7'))
		gauge[7] = new JustGage({
			id: "g7", 
			min: 0,
			max: 50,
			title: "s7",
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
	if(document.getElementById('g8'))
		gauge[8] = new JustGage({
			id: "g8", 
			min: 0,
			max: 50,
			title: "s8",
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
	if(document.getElementById('g9'))
		gauge[9] = new JustGage({
			id: "g9", 
			min: 0,
			max: 50,
			title: "s9",
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
	if(document.getElementById('g10'))
		gauge[10] = new JustGage({
			id: "g10", 
			min: 0,
			max: 50,
			title: "s10",
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
	if(document.getElementById('g11'))
		gauge[11] = new JustGage({
			id: "g11", 
			min: 0,
			max: 50,
			title: "s11",
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

	updateLights(lights);
};

var socket = io.connect(location.host);
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
socket.on('action', function(data) {
	var id = parseInt(data.substring(0, data.indexOf(':')));
	data = parseFloat(data.substring(data.indexOf(':') + 1, data.length));
	lights[id] = (data ? 1 : 0);
	updateLights(lights);	
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

function updateLights(lights){
	var c = document.getElementById("lightsCanvas");
	c.setAttribute('width', window.innerWidth);
	c.setAttribute('height', 80);
	var context = c.getContext("2d");
    var centerY = c.height / 2;
	numberOfLights = 8;
	for(i = 0; i < numberOfLights; i++){
		context.beginPath();
		context.arc((i + 1) * c.width/(numberOfLights + 1), centerY, 25, 0, 2 * Math.PI, false);
		if(lights[i])
			context.fillStyle = '#32cd32';
		else			
			context.fillStyle = 'gray';
		context.fill();
		context.lineWidth = 5;
		context.strokeStyle = 'black';//'#003300';
		context.stroke();
	}
}