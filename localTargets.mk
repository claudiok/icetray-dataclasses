#
#  $Id: localTargets.mk,v 1.2 2004/08/05 12:39:12 troy Exp $
#
# TDS: this is a hack...  ROOTCINT_MINUS_P and ROOTCINT_INC_FLAGS are
# reversed in common.mk.  My bad.

ROOTCINT_MINUS_P := 
ROOTCINT_INC_FLAGS := -p $(ROOTCINT_INC_FLAGS)

