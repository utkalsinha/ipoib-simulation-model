#
# OMNeT++/OMNEST Makefile for libIPoIBSimulationModel
#
# This file was generated with the command:
#  opp_makemake -f --deep --make-so -I../../CoRE4INET/src/linklayer/ethernet/base -I../../inet/src/inet/linklayer/common -I../../SharedClassesProj/src -I../../inet/src/inet/linklayer/ethernet -I../../inet/src -L../../CoRE4INET/out/$$\(CONFIGNAME\)/src -L../../inet/out/$$\(CONFIGNAME\)/src -L../../SharedClassesProj/out/$$\(CONFIGNAME\)/src -lCoRE4INET -lINET -lSharedClassesProj -DINET_IMPORT -KCORE4INET_PROJ=../../CoRE4INET -KINET_PROJ=../../inet -KSHAREDCLASSESPROJ_PROJ=../../SharedClassesProj
#

# Name of target to be created (-o option)
TARGET = libIPoIBSimulationModel$(SHARED_LIB_SUFFIX)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I../../CoRE4INET/src/linklayer/ethernet/base \
    -I../../inet/src/inet/linklayer/common \
    -I../../SharedClassesProj/src \
    -I../../inet/src/inet/linklayer/ethernet \
    -I../../inet/src \
    -I.

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L../../CoRE4INET/out/$(CONFIGNAME)/src -L../../inet/out/$(CONFIGNAME)/src -L../../SharedClassesProj/out/$(CONFIGNAME)/src  -lCoRE4INET -lINET -lSharedClassesProj
LIBS += -Wl,-rpath,`abspath ../../CoRE4INET/out/$(CONFIGNAME)/src` -Wl,-rpath,`abspath ../../inet/out/$(CONFIGNAME)/src` -Wl,-rpath,`abspath ../../SharedClassesProj/out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/EthernetHardwareAddressFields.o \
    $O/EthernetPortFrameListener.o \
    $O/GlobalListenerModule.o \
    $O/HCAPort.o \
    $O/IBHardWAddress.o \
    $O/ibSwitchLogic.o \
    $O/IPoIBLayer.o \
    $O/IPoIBSink.o \
    $O/IPTrafficGenerator.o \
    $O/QueuePair.o \
    $O/IPoIBFrame_m.o \
    $O/IPoIBFrameIB_m.o \
    $O/IPv4ARP_m.o \
    $O/IPv4ARPTotf_m.o \
    $O/IPv4PacketIB_m.o \
    $O/IPv4PacketOnly_m.o \
    $O/QPsendCompletion_m.o

# Message files
MSGFILES = \
    IPoIBFrame.msg \
    IPoIBFrameIB.msg \
    IPv4ARP.msg \
    IPv4ARPTotf.msg \
    IPv4PacketIB.msg \
    IPv4PacketOnly.msg \
    QPsendCompletion.msg

# Other makefile variables (-K)
CORE4INET_PROJ=../../CoRE4INET
INET_PROJ=../../inet
SHAREDCLASSESPROJ_PROJ=../../SharedClassesProj

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppenvir$D $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS) -DINET_IMPORT $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating shared library: $@
	$(Q)$(SHLIB_LD) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS) $(LDFLAGS)
	$(Q)$(SHLIB_POSTPROCESS) $O/$(TARGET)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f IPoIBSimulationModel IPoIBSimulationModel.exe libIPoIBSimulationModel.so libIPoIBSimulationModel.a libIPoIBSimulationModel.dll libIPoIBSimulationModel.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/EthernetHardwareAddressFields.o: EthernetHardwareAddressFields.cc \
	EthernetHardwareAddressFields.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h
$O/EthernetPortFrameListener.o: EthernetPortFrameListener.cc \
	$(CORE4INET_PROJ)/src/linklayer/ethernet/base/EtherFrameWithQTag_m.h \
	EthernetPortFrameListener.h \
	$(SHAREDCLASSESPROJ_PROJ)/src/IPv4PacketIBS_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/Ieee802Ctrl_m.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/linklayer/ethernet/EtherFrame_m.h \
	$(INET_PROJ)/src/inet/linklayer/ethernet/Ethernet.h
$O/GlobalListenerModule.o: GlobalListenerModule.cc \
	EthernetPortFrameListener.h \
	GlobalListenerModule.h
$O/HCAPort.o: HCAPort.cc \
	HCAPort.h \
	IPoIBFrameIB_m.h
$O/IBHardWAddress.o: IBHardWAddress.cc \
	IBHardWAddress.h
$O/IPTrafficGenerator.o: IPTrafficGenerator.cc \
	IPTrafficGenerator.h \
	$(SHAREDCLASSESPROJ_PROJ)/src/IPv4PacketIBS_m.h
$O/IPoIBFrameIB_m.o: IPoIBFrameIB_m.cc \
	IPoIBFrameIB_m.h
$O/IPoIBFrame_m.o: IPoIBFrame_m.cc \
	IPoIBFrame_m.h
$O/IPoIBLayer.o: IPoIBLayer.cc \
	IBHardWAddress.h \
	IPoIBFrameIB_m.h \
	IPoIBLayer.h \
	IPv4ARPTotf_m.h \
	QPsendCompletion_m.h \
	$(SHAREDCLASSESPROJ_PROJ)/src/IPv4PacketIBS_m.h
$O/IPoIBSink.o: IPoIBSink.cc \
	IPoIBSink.h \
	$(SHAREDCLASSESPROJ_PROJ)/src/IPv4PacketIBS_m.h
$O/IPv4ARPTotf_m.o: IPv4ARPTotf_m.cc \
	IPv4ARPTotf_m.h
$O/IPv4ARP_m.o: IPv4ARP_m.cc \
	IPv4ARP_m.h
$O/IPv4PacketIB_m.o: IPv4PacketIB_m.cc \
	IPv4PacketIB_m.h
$O/IPv4PacketOnly_m.o: IPv4PacketOnly_m.cc \
	IPv4PacketOnly_m.h
$O/QPsendCompletion_m.o: QPsendCompletion_m.cc \
	QPsendCompletion_m.h
$O/QueuePair.o: QueuePair.cc \
	IPoIBFrameIB_m.h \
	QPsendCompletion_m.h \
	QueuePair.h
$O/ibSwitchLogic.o: ibSwitchLogic.cc \
	IPoIBFrameIB_m.h \
	ibSwitchLogic.h

