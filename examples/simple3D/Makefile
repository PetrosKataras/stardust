.PHONY: Release Debug clobber install

CMAKE=cmake
DEBUG_DIR=debug
RELEASE_DIR=release

default: Release 

Debug:
	@mkdir -p $(DEBUG_DIR);
	@cd $(DEBUG_DIR); $(CMAKE) .. -DCMAKE_BUILD_TYPE=Debug;
	@$(MAKE) -C $(DEBUG_DIR);

Release: 
	@mkdir -p $(RELEASE_DIR);
	@cd $(RELEASE_DIR); $(CMAKE) .. -DCMAKE_BUILD_TYPE=Release;
	@$(MAKE) -C $(RELEASE_DIR);
	
install:
	@$(MAKE) -C $(RELEASE_DIR) install;

clobber:
	@rm -rf $(DEBUG_DIR);
	@rm -rf $(RELEASE_DIR);
