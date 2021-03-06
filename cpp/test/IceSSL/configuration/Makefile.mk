# **********************************************************************
#
# Copyright (c) 2003-2017 ZeroC, Inc. All rights reserved.
#
# This copy of Ice is licensed to you under the terms described in the
# ICE_LICENSE file included in this distribution.
#
# **********************************************************************

$(test)_dependencies = IceSSL Ice TestCommon

# Need to load certificates with functions from src/IceSSL/Util.h
$(test)[iphoneos]_cppflags		:= -Isrc
$(test)[iphonesimulator]_cppflags	:= -Isrc

tests += $(test)
