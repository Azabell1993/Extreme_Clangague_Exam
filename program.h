/*
  @file program.h
*/
#pragma once
#ifndef _PROGRAM_H
#define _PROGRAM_H
#ifdef __cplusplus
extern "C" {
#endif

#ifdef BUILD_MY_LIB
#define SHARED_LIB  __declspac(dllexport)
#else
#define SHARD_LIB   __declspac(dllexport)
#endif

#ifndef MYPASER_DYNAMIC
#define exam_service    paser_service_static
#endif

#ifndef PASER_CHECK
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#endif

#define PARK_PLUGIN_INTERFACE_VERSION   0x0104
#define MARIA_PLUGIN_INTERFACE_VERSION  0x010f

#ifndef PARK_DYNAMIC_PLUGIN
#define __PARK_DECL_PLUGIN(NAME, VERSION, PSIZE, DECLS)                                 \
int VERSION     =   PARK_PLUGIN_INTERFACE_VERSION;                                      \
int PSIZE       =   sizeof(struct st_park_plugin)                                       \
struct st_park_plugin   DCELS[] = {                                                     
    #define PARK2_DECL_PLUGIN__(NAME, VERSION, PSIZE, DECLS)                            \
    PARK_PLUGIN_EXPORT  int VERSION;                                                    \
    int VERSION = st_park2_plugin_interface_version;                                    \
    PARK_PLUGIN_EXPORT  int PSIZE;                                                      \
    int PSIZE = sizeof(struct st_park2_plugin);                                         \
    PARK_PLUGIN_EXPORT  struct st_park2_plugin  DECLS[];                                \
    struct st_park2_plugin  DECLS[] = {                                                 
    #else               

    #define __PARK_DECL_PLUGIN(NAME, VERSION, PSIZE, DECLS)                             \
    PARK_PLUGIN_EXPORT  int _park_plugin_interface_version;                             \
    int _park_plugin_interface_version  =   PARK_PLUGIN_INTERFACE_VERSION;              \
    PARK_PLUGIN_EXPORT  int _park_sizeof_struct_st_pluglin;                             \
    int _park_sizeof_struct_st_pluglin = sizeof(struct st_park_plugin);                 \
    PARK_PLUGIN_EXPORT  struct st_park_plugin _st_park2_plugin_declarations_[];         \
    struct st_park_plugin _st_park2_plugin_declarations_[] = {         
        #define PARK2_DECL_PLUGIN__(NAME, VERSION, PSIZE, DECLS)                        \
        PARK_PLUGIN_EXPORT int _st_park2_plugin_interface_version_;                     \
        int _st_park2_plugin_interface_version_ = st_park2_plugin_interface_version;    \
        PARK_PLUGIN_EXPORT int _st_sizeof_struct_plugin_;                               \
        int _st_sizeof_struct_plugin = sizeof(struct st_park2_plugin);                  \
        PARK_PLUGIN_EXPORT struct st_park2_plugin _export_plugin_declarations_[];       \
        struct st_park2_plugin  _export_plugin_declarations_[] = {
        #endif
        #define     PARK_DECL_PLUGIN(NAME)      \
        __PARK_DECL_PLUGIN(NAME,            \
                        EXTERN_ ##  NAME    ##  _park2_plugin_interface_version, \
                        EXTERN_ ##  NAME    ##  _sizeof_struct_plugin,           \
                        EXTERN_ ##  NAME    ##  _plugin)

        #define    __PARK2_DECL_PLUGIN(NAME)    \
        PARK2_DECL_PLUGIN__(NAME,    \
                        EXTERN_PARK_ ## NAME ## _ _park2_plugin_interface_version,     \
                        EXTERN_PARK_ ## NAME ## _sizeof_struct_plugin,                 \
                        EXTERN_PARK_ ## NAME ## _plugin)
    #define park_decl_plugin_end  ,   {0,0,0,0,0,0,0,0,0,0,0,0,0}}
    #define park2_decl_plugin_end ,   {0,0,0,0,0,0,0,0,0,0,0,0,0}}

enum enum_park_show_type {
    SHOW_UNDEF, SHOW_BOOL, SHOW_UINT, SHOW_ULONG,
    SHOW_ULONGLONG, SHOW_CHAR, SHOW_CHAR_PTR,
    SHOW_ARRAY, SHOW_FUNC, SHOW_DOUBLE,
    SHOW_SINT, SHOW_SLONG, SHOW_SLONGLONG, SHOW_SIMPLE_FUNC,
    SHOW_SIZE_T, SHOW_always_last
};


struct st_park_show_var {
    const char *name;
    void *value;
    enum enum_park_show_type type;
};

struct st_park_plugin {
    int                         type;
    int                         *info;
    const char                  *name;
    const char                  *author;
    const char                  *descr;
    int                         license;
    int                         (*init)(void*);
    int                         (*deinit)(void*);
    unsigned int                version;
    struct st_park_show_var     *status_vars;
    void                        * __reserved1;
    unsigned long               flags;
};

struct st_park2_plugin {
    int                         type;             
    void                        *info;           
    const char                  *name;     
    const char                  *author;   
    const char                  *descr;    
    int                         license;          
    int                         (*init)(void *);  
    int                         (*deinit)(void *);
    unsigned int                version; 
    struct st_park2_show_var    *status_vars;
    const char                  *version_info;  
    unsigned int                maturity; 
};
typedef struct {
    /*
        char            *str_info;
        unsigned int    number;
    */
   char *next_node;
   unsigned int number;

   /* input function pointer */
   void     (*func)(void* , void*);
} exam;

#define f_paser_service_st(...)      exam_service->struct_exam_ptr    (__VA_ARGS__) 

#define DEFINE_EXAM_FUNCTION(NAME) NAME(     \
    exam *exam_ptr                  \
)               

struct paser_service_st{
    int DEFINE_EXAM_FUNCTION((*struct_exam_ptr));
    
    /*
        input struct pointer function
        here space at define
    */
    bool is_struct_ptr;
};

extern struct paser_service_st *parser_service;



#ifdef __cplusplus
}
#endif

#define _PROGRAM_H
#endif

