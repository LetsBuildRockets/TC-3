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
			min: 0,
			max: 50,
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
	if(document.getElementById('g3'))
		gauge[3] = new JustGage({
			id: "g3", 
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
	if(document.getElementById('g4'))
		gauge[4] = new JustGage({
			id: "g4", 
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
	if(document.getElementById('g5'))
		gauge[5] = new JustGage({
			id: "g5", 
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
	if(document.getElementById('g6'))
		gauge[6] = new JustGage({
			id: "g6", 
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
	if(document.getElementById('g7'))
		gauge[7] = new JustGage({
			id: "g7", 
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
	if(document.getElementById('g8'))
		gauge[8] = new JustGage({
			id: "g8", 
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
	if(document.getElementById('g9'))
		gauge[9] = new JustGage({
			id: "g9", 
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
	if(document.getElementById('g10'))
		gauge[10] = new JustGage({
			id: "g10", 
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
	if(document.getElementById('g11'))
		gauge[11] = new JustGage({
			id: "g11", 
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