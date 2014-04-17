var yaml = require('js-yaml');
var fs = require('fs');
var sequencer = require('./components/sequencer');
var devices = require('./components/devices');
var actions = require('./components/actions');
var server = require('./components/server');
var serial = require('./components/serial');
var settings = yaml.safeLoad(fs.readFileSync('./config/settings.yaml', 'ascii'));

var loggerActions = require('./components/logger');

var date = new Date();
var logsFolder = settings.log.folder + date.getFullYear() + " " + date.getMonth() + " " + date.getDay() + "  " + date.getHours() + " " + date.getMinutes() + " " + date.getSeconds();
fs.mkdir(logsFolder);

loggerActions.init(settings, logsFolder, "actions");

server.init(settings, sequencer, devices, actions);
actions.init(settings, sequencer, serial, loggerActions);
sequencer.init(settings, actions);
devices.init(settings);
serial.init(settings);