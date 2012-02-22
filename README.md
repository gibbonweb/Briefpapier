# Briefpapier

Briefpapier is a small app with a simple purpose: It lets you merge a letter with a stationery file. The letter, as well as the stationery file, have to be PDF documents with matching dimensions.

It is basically a GUI wrapper for [The PDF Toolkit](http://www.pdflabs.com/tools/pdftk-the-pdf-toolkit/) and is currently only tested on Mac OS 10.7.

It uses Qt 4.8 but should run on lower versions, since it doesn't use any cutting edge features. I'm too lazy to investigate.

## Requirements/Recommendations:

1. [Qt SDK](http://qt.nokia.com/downloads/) 1.2 or higher
1. [The PDF Toolkit](http://www.pdflabs.com/tools/pdftk-the-pdf-toolkit/) 1.44 or higher

## Installation:

1. [Install Pdftk](http://www.pdflabs.com/docs/install-pdftk/).
1. Clone Briefpapier to your hard drive and build it. Alternatively, just [get the binary](https://github.com/downloads/gibbonweb/Briefpapier/Briefpapier.dmg) and put it in your Applications folder.
1. There is no third step.

## Caveats / Limitations:

1. German GUI. Feel free to i18n'ize and L10n'ize the sh*t out of it. I just need it in German. ;)
1. Supposedly only works with single page input for now. Everything else is untested and entirely up to `pdftk`. See their manfile or just try it out to find out more. ;)