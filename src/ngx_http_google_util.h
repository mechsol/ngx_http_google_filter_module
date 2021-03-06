//
//  ngx_http_google_util.h
//  nginx
//
//  Created by Cube on 14/12/15.
//  Copyright (c) 2014 Cube. All rights reserved.
//

#ifndef _NGX_HTTP_GOOGLE_UTIL_H
#define _NGX_HTTP_GOOGLE_UTIL_H

#include "ngx_http_google_filter_module.h"
#include <time.h>
#include <openssl/md5.h>

ngx_str_t
ngx_http_google_trim(char * str, size_t len);

ngx_array_t * /* ngx_str_t */
ngx_http_google_explode(ngx_http_request_t * r,
                        ngx_str_t          * v,
                        const char         * de);

ngx_str_t *
ngx_http_google_implode(ngx_http_request_t * r,
                        ngx_array_t        * a, /* ngx_str_t */
                        const char         * de);

ngx_array_t * /* ngx_keyval_t */
ngx_http_google_explode_kv(ngx_http_request_t * r,
                           ngx_str_t          * v,
                           const char         * de);

ngx_str_t *
ngx_http_google_implode_kv(ngx_http_request_t * r,
                           ngx_array_t        * a, /* ngx_keyval_t */
                           const char         * de,
                           const ngx_int_t);

ngx_int_t
ngx_http_google_debug(ngx_pool_t * pool, const char * fmt, ...);

ngx_int_t
ngx_http_google_validate_user(ngx_http_request_t * r, const ngx_int_t keyid, const ngx_uint_t endtime, const ngx_str_t * auth_code, ngx_int_t * rkeyid);

ngx_int_t
ngx_http_google_get_validate_token(ngx_http_request_t * r, const ngx_str_t * key, const ngx_uint_t endtime, ngx_uint_t * rkeyid, ngx_str_t * auth_code);

#endif /* defined(_NGX_HTTP_GOOGLE_UTIL_H) */
