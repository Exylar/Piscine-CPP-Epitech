const {
  override,
  addDecoratorsLegacy,
  disableEsLint,
} = require("customize-cra");

module.exports = override(
  // disable eslint in webpack
  disableEsLint(),
  // enable legacy decorators babel plugin
  addDecoratorsLegacy()
);