/*
 * Copyright (c) 2006-2014 Erik Ekman <yarrick@kryo.se>,
 * 2006-2009 Bjorn Andersson <flex@kryo.se>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef __DNS_H__
#define __DNS_H__

#define T_PRIVATE 65399
/* Undefined RR type; "private use" range, see
 * http://www.bind9.net/dns-parameters */
#define T_UNSET 65432
/* Unused RR type, never actually sent */

#define QUERY_NAME_SIZE 256

struct query {
    char name[QUERY_NAME_SIZE];
    unsigned short type;
    unsigned short rcode;
    unsigned short id;
    struct sockaddr_storage destination;
    socklen_t dest_len;
    struct sockaddr_storage from;
    socklen_t fromlen;
    unsigned short id2;
    struct sockaddr_storage from2;
    socklen_t fromlen2;
};

typedef enum { QR_QUERY = 0, QR_ANSWER = 1 } qr_t;

extern int dnsc_use_edns0;

int dns_encode(char *, size_t, struct query *, qr_t, char *, size_t);
int dns_encode_ns_response(char *buf, size_t buflen, struct query *q, char *topdomain);
int dns_encode_a_response(char *buf, size_t buflen, struct query *q);
unsigned short dns_get_id(char *packet, size_t packetlen);
int dns_decode(char *, size_t, struct query *, qr_t, char *, size_t);

#endif /* _DNS_H_ */
