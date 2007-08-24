/*

$VER: 02.00 (2005/08/10)
 
    Portability update.
   
    FM_Adjust_Query support.
   
    Support new color specifications.
 
$VER: 01.00 (2005/04/06)

*/

#include "Project.h"

///METHODS
F_METHOD_PROTO(void,Adjust_New);
F_METHOD_PROTO(void,Adjust_Query);
F_METHOD_PROTO(void,Adjust_ToString);
F_METHOD_PROTO(void,Adjust_ToObject);
//+

F_QUERY()
{
    switch (Which)
    {
        case FV_Query_ClassTags:
        {
            STATIC F_METHODS_ARRAY =
            {
                F_METHODS_ADD(Adjust_Query, "FM_Adjust_Query"),
                F_METHODS_ADD(Adjust_ToString, "FM_Adjust_ToString"),
                F_METHODS_ADD(Adjust_ToObject, "FM_Adjust_ToObject"),
                F_METHODS_ADD_STATIC(Adjust_New, FM_New),

                F_ARRAY_END
            };

            STATIC F_TAGS_ARRAY =
            {
                F_TAGS_ADD_SUPER(Adjust),
                F_TAGS_ADD_LOD,
                F_TAGS_ADD_METHODS,

                F_ARRAY_END
            };

            return F_TAGS;
        }
    }
    return NULL;
}

