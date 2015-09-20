var gauge = new Array();
var lights = new Array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
var lineChartData = new Object();
var chart = new Object();
var time = 0;
var startTime = (new Date()).getTime();

var identifiers = location.href.split("/");
  
window.onload = function(){
  if(identifiers[identifiers.length-1] == "control") {
    document.getElementById("run").style.visibility = "visible";
    document.getElementById("stop").style.visibility = "visible";
  } else {
    document.getElementById("run").style.visibility = "hidden";
    document.getElementById("stop").style.visibility = "hidden";
  }
  
  
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
			max: 1024,
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
		
	lineChartData = {
			labels : [],
			datasets : [
				{
					fillColor : "rgba(0,0,0,0)",
					strokeColor : "rgba(220,220,220,1)",
					pointColor : "rgba(220,220,220,1)",
					pointStrokeColor : "#fff",
					data : []
				},
				{
					fillColor : "rgba(0,0,0,0)",
					strokeColor : "rgba(151,187,205,1)",
					pointColor : "rgba(151,187,205,1)",
					pointStrokeColor : "#fff",
					data : []
				},
				{
					fillColor : "rgba(0,0,0,0)",
					strokeColor : "rgba(151,187,205,1)",
					pointColor : "rgba(151,187,205,1)",
					pointStrokeColor : "#fff",
					data : []
				},
				{
					fillColor : "rgba(0,0,0,0)",
					strokeColor : "rgba(151,187,205,1)",
					pointColor : "rgba(151,187,205,1)",
					pointStrokeColor : "#fff",
					data : []
				},
				{
					fillColor : "rgba(0,0,0,0)",
					strokeColor : "rgba(151,187,205,1)",
					pointColor : "rgba(151,187,205,1)",
					pointStrokeColor : "#fff",
					data : []
				}
			]
		}

	chart = new Chart(document.getElementById("graphCanvas").getContext("2d"));
	chart.Line(lineChartData, {animation: true});

	updateLights();
}

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
	time = data;
	if(gauge[0])
		gauge[0].refresh(parseFloat(data));
	if(data >= 0) {
		data = "+" + data;
	}
  document.getElementById('time').value = ('T'+data);
});
socket.on('device', function(data) {
	while(data.length > 1){
		var id = parseInt(data.substring(0, data.indexOf(':'))) + 1;
		var state = parseFloat(data.substring(data.indexOf(':') + 1, data.indexOf('\n'))).toFixed(2);
		data = data.substring(data.indexOf('\n') + 1, data.length);
		if(lineChartData.datasets[id]) {
      lineChartData.datasets[id].data.shift()
			lineChartData.datasets[id].data[10] = state;
    }
		if(gauge[id])
			gauge[id].refresh(state);
	}
	updateChart();
});
socket.on('action', function(data) {
	while(data.length > 1){
		var id = parseInt(data.substring(0, data.indexOf(':')));
		var state = parseFloat(data.substring(data.indexOf(':') + 1, data.indexOf('\n')));
		data = data.substring(data.indexOf('\n') + 1, data.length);
		lights[id] = (state ? 1 : 0);
		updateLights(lights);
	}
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

function updateChart(){	
  lineChartData.labels.shift();
  var elapsed = Math.round((new Date().getTime() - startTime)/1000);
	lineChartData.labels[10] = elapsed + ',  ' + document.getElementById('time').value;	
	chart.Line(lineChartData, {animation: false});
}

function updateLights(){
	var c = document.getElementById("lightsCanvas");
	c.setAttribute('width', window.innerWidth);
	c.setAttribute('height', 40);
	var context = c.getContext("2d");
    var centerY = c.height / 2;
	numberOfLights = lights.length;
	for(i = 0; i < numberOfLights; i++){
		context.beginPath();
		context.arc((i + 1) * c.width/(numberOfLights + 1), centerY, 10, 0, 2 * Math.PI, false);
		if(lights[i])
			context.fillStyle = '#32cd32';
		else			
			context.fillStyle = 'gray';
		context.fill();
		context.lineWidth = 2;
		context.strokeStyle = 'black';//'#003300';
		context.stroke();
	}
}

document.onkeydown = function(evt){    
   var key = evt.keyCode;
   if(identifiers[identifiers.length-1] == "control") {
     if(key == 27) {
       stop();
     }
     if(key == 13) {
       run();
     }
   }
}