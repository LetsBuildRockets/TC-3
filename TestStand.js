var yaml = require('js-yaml');
var fs = require('fs');
var sequencer = require('./components/sequencer');
var devices = require('./components/devices');
var actions = require('./components/actions');
var server = require('./components/server');
var serial = require('./components/serial');
var settings = yaml.safeLoad(fs.readFileSync('./config/settings.yaml', 'ascii'));

server.init(settings, sequencer, devices, actions);
actions.init(settings, serial);
sequencer.init(actions, settings);
devices.init(settings);
serial.init(settings);