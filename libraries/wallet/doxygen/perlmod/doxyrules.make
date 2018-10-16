DOXY_EXEC_PATH = C:/xmet/libraries/wallet
DOXYFILE = C:/xmet/libraries/wallet/Doxyfile
DOXYDOCS_PM = C:/xmet/libraries/wallet/doxygen/perlmod/DoxyDocs.pm
DOXYSTRUCTURE_PM = C:/xmet/libraries/wallet/doxygen/perlmod/DoxyStructure.pm
DOXYRULES = C:/xmet/libraries/wallet/doxygen/perlmod/doxyrules.make

.PHONY: clean-perlmod
clean-perlmod::
	rm -f $(DOXYSTRUCTURE_PM) \
	$(DOXYDOCS_PM)

$(DOXYRULES) \
$(DOXYMAKEFILE) \
$(DOXYSTRUCTURE_PM) \
$(DOXYDOCS_PM): \
	$(DOXYFILE)
	cd $(DOXY_EXEC_PATH) ; doxygen "$<"
