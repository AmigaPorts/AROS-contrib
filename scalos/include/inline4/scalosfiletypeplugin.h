#ifndef INLINE4_SCALOSFILETYPEPLUGIN_H
#define INLINE4_SCALOSFILETYPEPLUGIN_H

/*
** This file was auto generated by idltool 52.7.
**
** It provides compatibility to OS3 style library
** calls by substituting functions.
**
** Do not edit manually.
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef SCALOS_SCALOS_H
#include <scalos/scalos.h>
#endif
#include <interfaces/scalosfiletypeplugin.h>

/* Inline macros for Interface "main" */
#define SCAToolTipInfoString(ttshd, args) IScalosFileTypePlugin->SCAToolTipInfoString((ttshd), (args)) 

#endif /* INLINE4_SCALOSFILETYPEPLUGIN_H */
