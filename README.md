## *Dust = openFrameworks + Equalizer

Stardust attempts to bring the benefits and functionality of [openFrameworks](http://openframeworks.cc/) into cluster environments and distributed graphics through the use of [Equalizer](http://www.equalizergraphics.com/). Essentially this means that one can run openFrameworks powered applications in visualization clusters of any size, given sufficient resources ( thanks to and powered by Equalizer ). 

Its currently tested under Linux ( Xubuntu 14.10 ) and MacOS X ( Yosemite 10.10.4 with the GLX backend of Equalizer and not the AGL ). For Mac OS X you can install XQuartz [here](http://xquartz.macosforge.org/landing/). Port to Windows are more than welcome.

Stardust is a work in progress but hopefully in a state where people can give it a try. Any suggestions, feedback, contributions etc. are more than welcome! 

If you notice a bug or see something that you think it could be done in a different / better way please open issue or even better submit a pull request!

A prerequisite for working with stardust is reading the Equalizer User & Programming Guide. You have to fill out a small survey for obtaining the guide [here](http://www.equalizergraphics.com/survey.html). A lot of stuff are not necessarily relevant to stardust at this point but it gives a clear overview of the general philosophy and model of Equalizer, plus details on the distributed objects functionality, setting up visualization clusters for use with eq and various other important aspects.

#### How To:

`$STARDUST_ROOT` will be the directory where you cloned stardust for the purposes of this README.

1. Recursively clone stardust and dependencies :  
`git clone --recursive git@github.com:PetrosKataras/stardust.git`

2. Install dependencies (Linux) and compile openFrameworks. 

  Linux:  
  `cd $STARDUST_ROOT/libs/openFrameworks/scripts/linux/ubuntu && ./install_dependencies.sh`  
  `cd $STARDUST_ROOT/libs/openFrameworks/scripts/linux && ./compileOF.sh`  
  MacOS X:  
  `cd $STARDUST_ROOT/libs/openFrameworks/libs/openFrameworksCompiled/project && make`  

3. Compile and install Equalizer and dependencies :  

  Linux:  
  `cd $STARDUST_ROOT/utils/linux && ./install_EQ_dependencies.sh`  
  `cd $STARDUST_ROOT/utils/linux && ./build_EQ.sh`  
  MacOS X:  
  Install [brew](http://brew.sh/) and run on a terminal:  
  `cd $STARDUST_ROOT/utils/osx && ./install_EQ_dependencies.sh`  
  `cd $STARDUST_ROOT/utils/osx && ./build_EQ.sh`  

4. Compile stardust and optionally install ( run make followed by make install ) stardust:  
  `cd $STARDUST_ROOT && make`

This command will build a release vesion of stardust and the included examples ( run `make Debug` for a debug version ).  
To run the examples `cd release/examples` or `cd debug/examples` depending on your target and you can take it from there.  

The default installation path is under `$STARDUST_ROOT/install`.  

If you want to use a custom directory for an application using stardust the only requirement is to set `Stardust_DIR` to point to the directory where stardust produced its export configuration files. 

If you have installed stardust with `make install` then `Stardust_DIR` should point to `$INSTALL_PREFIX/share/stardust/cmake` . If you haven't installed stardust you can simply point `Stardust_DIR` to the directory where it was built.

You can change this and any other project variable with the cmake tool of your choice or by just specifying command line options.

Stardust, following Equalizer's licensing scheme, is released under the terms of the LGPL 2.1 license. 
