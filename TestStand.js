var yaml = require('js-yaml');
var fs = require('fs');
var sequencer = require('./components/sequencer');
var devices = require('./components/devices');
var actions = require('./components/actions');
var server = require('./components/server');
var serial = require('./components/serial');
var settings = yaml.safeLoad(fs.readFileSync('./config/settings.yaml', 'ascii'));

var date = new Date();
var logsFolder = settings.log.folder + date.getFullYear() + " " + date.getMonth() + " " + date.getDay() + "  " + date.getHours() + " " + date.getMinutes() + " " + date.getSeconds();
fs.mkdir(logsFolder);
var logs = [];
var logger = require('./components/logger');

logs["actions"] = new logger(settings, logsFolder, "actions");
logs["devices"] = new logger(settings, logsFolder, "devices");

server.init(settings, sequencer, devices, actions);
sequencer.init(settings, devices, actions);
actions.init(settings, sequencer, serial, logs["actions"]);
devices.init(settings, sequencer, serial, logs["devices"]);
serial.init(settings, devices.updateDevices);