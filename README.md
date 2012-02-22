# Briefpapier

Briefpapier is a small app with a simple purpose: It lets you merge a letter with a stationery file. The letter, as well as the stationery file, have to be PDF documents with matching dimensions.

It is basically a GUI wrapper for [The PDF Toolkit](http://www.pdflabs.com/tools/pdftk-the-pdf-toolkit/) and is currently only tested on Mac OS 10.7.

It uses Qt 4.8 but should run on lower versions, since it doesn't use any cutting edge features. I'm too lazy to investigate.

Requirements/Recommendations:
1. [Qt SDK](http://qt.nokia.com/downloads/) 1.2 or higher
1. [The PDF Toolkit](http://www.pdflabs.com/tools/pdftk-the-pdf-toolkit/)