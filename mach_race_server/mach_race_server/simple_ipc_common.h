/*
 * ______  ___            ______
 * ___   |/  /_____ _________  /_
 * __  /|_/ /_  __ `/  ___/_  __ \
 * _  /  / / / /_/ // /__ _  / / /
 * /_/  /_/  \__,_/ \___/ /_/ /_/
 * ________
 * ___  __ \_____ ___________
 * __  /_/ /  __ `/  ___/  _ \
 * _  _, _// /_/ // /__ /  __/
 * /_/ |_| \__,_/ \___/ \___/
 *
 * Mach Race OS X Local Privilege Escalation Exploit
 *
 * Created by reverser on 27/04/15.
 * Copyright (c) fG!, 2015, 2016. All rights reserved.
 * reverser@put.as - https://reverse.put.as
 *
 * simple_ipc_common.h
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 * derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _SIMPLE_IPC_COMMON_H_
#define _SIMPLE_IPC_COMMON_H_
   
#include <mach/mach.h>
#include <servers/bootstrap.h>
   
#define SERVICE_NAME   "com.put.as.mach_race1"
#define DEFAULT_MSG_ID 400
   
#define EXIT_ON_MACH_ERROR(msg, retval, success_retval) \
    if (kr != success_retval) { mach_error(msg ":" , kr); exit((retval)); }
   
typedef struct {
    mach_msg_header_t header;
    mach_msg_body_t   body;
    mach_msg_port_descriptor_t data;
} msg_format_send_t;
   
typedef struct {
    mach_msg_header_t  header;
    mach_msg_body_t    body;
    mach_msg_port_descriptor_t data;
    mach_msg_mac_trailer_t trailer;
} msg_format_recv_t;
   
#endif // _SIMPLE_IPC_COMMON_H_
