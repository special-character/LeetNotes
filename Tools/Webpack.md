# Webpack

Builds a dependency graph of modules that represent the entire application.

1. Entry
* Starting point of the application
* Like a root node in the dependency graph

2. Output
* How to treat bundled
* i.e. the name of our bundles and where to find them

3. Loaders
* Every file is a 'module'
* Transform these files into modules as they are added to the dependency graph
* Two steps - 1) Identify what loader to transform a file. 2) Transform the file into a module and add to the dependency graph


4. Plugins
* Perform special actions on "chunks" of bundled modules
* E.X: Hot Module Replacement, HTML template when bundling, etc...
