const addon = require('bindings')('automate');

addon.getAllScreens((error, position) => {
  if (error) return console.log(error);
  console.log(position);
});

addon.getScreenAtPoint(5, 5, (error, position) => {
  if (error) return console.log(error);
  console.log(position);
});


module.exports = addon;
