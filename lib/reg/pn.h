/**
 * SIP Push Notification support - RFC 8599
 * Copyright (C) 2020 OpenSIPS Solutions
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 */

#ifndef __REG_PN_H__
#define __REG_PN_H__

#include "../../parser/msg_parser.h"
#include "../../parser/parse_uri.h"
#include "../../str_list.h"
#include "../../ut.h"

struct pn_provider {
	str name;
	str feature_caps;
	int append_fcaps;

	struct pn_provider *next;
};

enum pn_action {
	PN_NONE,            /* no 'pn-provider' was given */
	PN_UNSUPPORTED_PNS, /* the given 'pn-provider' value is not supported */
	PN_LIST_ALL_PNS,    /* only 'pn-provider' given, no value */
	PN_LIST_ONE_PNS,    /* a known 'pn-provider' value was given */
	PN_ON,              /* all required 'pn-*' params are given */
};

/* modparams */
extern int pn_enable;
extern int pn_pnsreg_interval;
extern int pn_trigger_interval;
extern char *pn_provider_param;
extern char *_pn_ct_params;
extern char *_pn_providers;

/* useful fixups */
extern str_list *pn_ct_params;  /* list of parsed match params */
extern struct pn_provider *pn_providers;


/**
 * initialize RFC 8599 support
 */
int pn_init(void);


/**
 * look for any RFC 8599 URI parameters and take the appropriate action
 */
enum pn_action pn_inspect_ct_params(const str *ct_uri);


#endif /* __REG_PN_H__ */