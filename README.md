## *Dust = [openFrameworks](https://github.com/openframeworks/openFrameworks) + [Equalizer](https://github.com/Eyescale/Equalizer)

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
