## *Dust = openFrameworks + Equalizer

Stardust attempts to bring the benefits and functionality of [openFrameworks](http://openframeworks.cc/) into cluster environments and distributed graphics through the use of [Equalizer](http://www.equalizergraphics.com/). Essentially this means that one can run openFrameworks powered applications in visualization clusters of any size, given sufficient resources ( thanks to and powered by Equalizer ). 

For now stardust is Linux-only but since both openFrameworks and Equalizer are cross platform it should be possible to port in MacOS and Windows.  

Stardust is a work in progress but hopefully in a state where people can try it out and play around with. Any suggestions, feedback, contributions etc. are more than welcome! 

The attempt with stardust so far has been to follow as closely as possible the internal models of both openFrameworks and Equalizer and where this has not been possible the changes should be the least invasive. If you notice a bug or see something that you think it could be done in a different / better way please open issue.

A prerequisite for working with stardust is reading the Equalizer User & Programming Guide. You have to fill out a small survey for obtaining the guide [here](http://www.equalizergraphics.com/survey.html). A lot of stuff are not necessarily relevant to stardust at this point but it gives a clear overview of the general philosophy and model of Equalizer, plus details on the distributed objects functionality, setting up visualization clusters for use with eq and various other important aspects.

#### How To:

`$STARDUST_DIR` will be the directory where you cloned stardust.

1. Recursively clone stardust and dependencies :  
`git clone --recursive git@github.com:PetrosKataras/stardust.git`

2. Install dependencies and compile openFrameworks as per usual.  
`cd $STARDUST_DIR/libs/openFrameworks/scripts/linux/ubuntu && ./install_dependencies.sh`  
`cd $STARDUST_DIR/libs/openFrameworks/scripts/linux && ./compileOF.sh`

3. Compile and install Equalizer and dependencies :  
`cd $STARDUST_DIR/utils/linux && ./install_EQ_dependencies.sh`  
`cd $STARDUST_DIR/utils/linux && ./build_EQ.sh`

4. Compile and optionally install ( run make followed by make install ) stadust:  
`cd $STARDUST_DIR && make`

The default install path for stardust is under `$STARDUST_DIR/install`.
You can change this and any other project variable with the cmake tool of your choice or by just specifying command line options.
