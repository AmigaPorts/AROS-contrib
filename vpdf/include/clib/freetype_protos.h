#ifndef CLIB_FREETYPE_PROTOS_H
#define CLIB_FREETYPE_PROTOS_H

/*
	Note that this is *NOT*, I repeat *NOT* a public include file, it is
	simply so that we can create a fake libfreetype.a stubs library!

	It is a mess! Clean it up if you like, but I'm not going to ;)

*/




  FT_Error  FT_Init_FreeType( FT_Library  *alibrary );

  void  FT_Library_Version( FT_Library   library,
FT_Int      *amajor,                      FT_Int      *aminor,                      FT_Int      *apatch );


  FT_Error  FT_Done_FreeType( FT_Library  library );

  FT_Error  FT_New_Face( FT_Library   library,               const char*  filepathname,               FT_Long      face_index,               FT_Face     *aface );


  FT_Error  FT_New_Memory_Face( FT_Library      library,                      const FT_Byte*  file_base,                      FT_Long         file_size,                      FT_Long         face_index,                      FT_Face        *aface );

  FT_Error  FT_Open_Face( FT_Library           library,                const FT_Open_Args*  args,                FT_Long              face_index,                FT_Face             *aface );

  FT_Error  FT_Attach_File( FT_Face      face,                  const char*  filepathname );


  FT_Error  FT_Attach_Stream( FT_Face        face,                    FT_Open_Args*  parameters );


  FT_Error  FT_Done_Face( FT_Face  face );

  FT_Error  FT_Set_Char_Size( FT_Face     face,                    FT_F26Dot6  char_width,
                    FT_F26Dot6  char_height,                    FT_UInt     horz_resolution,
                    FT_UInt     vert_resolution );
  FT_Error  FT_Set_Pixel_Sizes( FT_Face  face,
                      FT_UInt  pixel_width,
                      FT_UInt  pixel_height );


  FT_Error  FT_Load_Glyph( FT_Face   face,
                 FT_UInt   glyph_index,
                 FT_Int32  load_flags );


  FT_Error  FT_Load_Char( FT_Face   face,
                FT_ULong  char_code,
                FT_Int32  load_flags );

  void  FT_Set_Transform( FT_Face     face,
                    FT_Matrix*  matrix,
                    FT_Vector*  delta );



  FT_Error  FT_Render_Glyph( FT_GlyphSlot    slot,
                   FT_Render_Mode  render_mode );


  FT_Error  FT_Get_Kerning( FT_Face     face,
                  FT_UInt     left_glyph,
                  FT_UInt     right_glyph,
                  FT_UInt     kern_mode,
                  FT_Vector  *akerning );


  FT_Error  FT_Get_Glyph_Name( FT_Face     face,
                     FT_UInt     glyph_index,
                     FT_Pointer  buffer,
                     FT_UInt     buffer_max );


  const char*  FT_Get_Postscript_Name( FT_Face  face );

  FT_Error  FT_Select_Charmap( FT_Face      face,
                     FT_Encoding  encoding );

  FT_Error  FT_Set_Charmap( FT_Face     face,
                  FT_CharMap  charmap );

  FT_UInt  FT_Get_Char_Index( FT_Face   face,
                     FT_ULong  charcode );

  FT_ULong  FT_Get_First_Char( FT_Face   face,
                     FT_UInt  *agindex );


  FT_ULong  FT_Get_Next_Char( FT_Face    face,
                    FT_ULong   char_code,
                    FT_UInt   *agindex );

  FT_Uint  FT_Get_Name_Index( FT_Face     face,
                     FT_String*  glyph_name );


  FT_Long  FT_MulDiv( FT_Long  a,
             FT_Long  b,
             FT_Long  c );

  FT_Long  FT_MulFix( FT_Long  a,
             FT_Long  b );

  FT_Long  FT_DivFix( FT_Long  a,
             FT_Long  b );

  FT_Fixed  FT_CeilFix( FT_Fixed  a );


  void  FT_Vector_Transform( FT_Vector*  vec,
                       const FT_Matrix*  matrix );

  FT_Error  FT_Outline_Get_BBox( FT_Outline*  outline,
                       FT_BBox     *abbox );

  FT_Error  FT_Get_BDF_Charset_ID( FT_Face       face,
                         const char*  *acharset_encoding,
                         const char*  *acharset_registry );

  FT_Error  FT_Get_BDF_Property( FT_Face           face,
                       const char*       prop_name,
                       BDF_PropertyRec  *aproperty );

  FT_Error  FTC_Manager_New( FT_Library          library,
                   FT_UInt             max_faces,
                   FT_UInt             max_sizes,
                   FT_ULong            max_bytes,
                   FTC_Face_Requester  requester,
                   FT_Pointer          req_data,
                   FTC_Manager        *amanager );

  void  FTC_Manager_Reset( FTC_Manager  manager );

  void  FTC_Manager_Done( FTC_Manager  manager );

  FT_Error  FTC_Manager_LookupFace( FTC_Manager  manager,
                           FTC_FaceID   face_id,
                           FT_Face     *aface );

  FT_Error  FTC_Manager_LookupSize( FTC_Manager  manager,
                          FTC_Scaler   scaler,
                          FT_Size     *asize );

void  FTC_Node_Unref( FTC_Node     node,
                  FTC_Manager  manager );

void   FTC_Manager_RemoveFaceID( FTC_Manager  manager,
                            FTC_FaceID   face_id );

 FT_Error   FTC_CMapCache_New( FTC_Manager     manager,
                     FTC_CMapCache  *acache );


 FT_UInt   FTC_CMapCache_Lookup( FTC_CMapCache  cache,
                        FTC_FaceID     face_id,
                        FT_Int         cmap_index,
                        FT_UInt32      char_code );

FT_Error   FTC_ImageCache_New( FTC_Manager      manager,
                      FTC_ImageCache  *acache );
                      
 FT_Error   FTC_ImageCache_Lookup( FTC_ImageCache  cache,
                         FTC_ImageType   type,
                         FT_UInt         gindex,
                         FT_Glyph       *aglyph,
                         FTC_Node       *anode );
                         
                         
 FT_Error   FTC_SBitCache_New( FTC_Manager     manager,
                     FTC_SBitCache  *acache );                      
                         
                         
  FT_Error FTC_SBitCache_Lookup( FTC_SBitCache    cache,
                        FTC_ImageType    type,
                        FT_UInt          gindex,
                        FTC_SBit        *sbit,
                        FTC_Node        *anode );
                         
  FT_Error  FT_Get_Glyph( FT_GlyphSlot  slot,
                FT_Glyph     *aglyph );

  FT_Error  FT_Glyph_Copy( FT_Glyph   source,
                 FT_Glyph  *target );

  FT_Error  FT_Glyph_Transform( FT_Glyph    glyph,
                      FT_Matrix*  matrix,
                      FT_Vector*  delta );


  void  FT_Glyph_Get_CBox( FT_Glyph  glyph,
                     FT_UInt   bbox_mode,
                     FT_BBox  *acbox );

  FT_Error  FT_Glyph_To_Bitmap( FT_Glyph*       the_glyph,
                      FT_Render_Mode  render_mode,
                      FT_Vector*      origin,
                      FT_Bool         destroy );

  void  FT_Done_Glyph( FT_Glyph  glyph );


  void  FT_Matrix_Multiply( const FT_Matrix*  a,
                      FT_Matrix*  b );

  FT_Error  FT_Matrix_Invert( FT_Matrix*  matrix );

  FT_Error  FT_Stream_OpenGzip( FT_Stream  stream,
                      FT_Stream  source );

  FT_ListNode  FT_List_Find( FT_List  list,
                void*    data );

  void  FT_List_Add( FT_List      list,
               FT_ListNode  node );

  void  FT_List_Insert( FT_List      list,
                  FT_ListNode  node );

  void  FT_List_Remove( FT_List      list,
                  FT_ListNode  node );

  void  FT_List_Up( FT_List      list,
              FT_ListNode  node );

  FT_Error  FT_List_Iterate( FT_List           list,
                   FT_List_Iterator  iterator,
                   void*             user );

  void  FT_List_Finalize( FT_List             list,
                    FT_List_Destructor  destroy,
                    FT_Memory           memory,
                    void*               user );

  FT_Error  FT_Get_Multi_Master( FT_Face           face,
                       FT_Multi_Master  *amaster );

  FT_Error  FT_Set_MM_Design_Coordinates( FT_Face   face,
                                FT_UInt   num_coords,
                                FT_Long*  coords );

  FT_Error  FT_Set_MM_Blend_Coordinates( FT_Face    face,
                               FT_UInt    num_coords,
                               FT_Fixed*  coords );

  FT_Error  FT_Add_Module( FT_Library              library,
                 const FT_Module_Class*  clazz );

  FT_Module  FT_Get_Module( FT_Library   library,
                 const char*  module_name );

  FT_Error  FT_Remove_Module( FT_Library  library,
                    FT_Module   module );

  FT_Error  FT_New_Library( FT_Memory    memory,
                  FT_Library  *alibrary );


  FT_Error  FT_Done_Library( FT_Library  library );


  void  FT_Set_Debug_Hook( FT_Library         library,
                     FT_UInt            hook_index,
                     FT_DebugHook_Func  debug_hook );


  void  FT_Add_Default_Modules( FT_Library  library );

  FT_Error  FT_Outline_Decompose( FT_Outline*              outline,
                        const FT_Outline_Funcs*  func_interface,
                        void*                    user );
  FT_Error  FT_Outline_New( FT_Library   library,
                  FT_UInt      numPoints,
                  FT_Int       numContours,
                  FT_Outline  *anoutline );


  FT_Error  FT_Outline_New_Internal( FT_Memory    memory,
                           FT_UInt      numPoints,
                           FT_Int       numContours,
                           FT_Outline  *anoutline );

  FT_Error  FT_Outline_Done( FT_Library   library,
                   FT_Outline*  outline );


  FT_Error  FT_Outline_Done_Internal( FT_Memory    memory,
                            FT_Outline*  outline );


  FT_Error  FT_Outline_Check( FT_Outline*  outline );

  void  FT_Outline_Get_CBox( const FT_Outline*  outline,
                       FT_BBox     *acbox );

  void  FT_Outline_Translate( const FT_Outline*  outline,
                        FT_Pos       xOffset,
                        FT_Pos       yOffset );


  FT_Error  FT_Outline_Copy( const FT_Outline*  source,
                   FT_Outline  *target );

  void  FT_Outline_Transform( const FT_Outline*  outline,
                        const FT_Matrix*   matrix );

  FT_Error  FT_Outline_Embolden( FT_Outline*  outline,
                                 FT_Pos       strength );

  void  FT_Outline_Reverse( FT_Outline*  outline );

  FT_Error  FT_Outline_Get_Bitmap( FT_Library   library,
                         FT_Outline*  outline,
                         const FT_Bitmap   *abitmap );

  FT_Error  FT_Outline_Render( FT_Library         library,
                     FT_Outline*        outline,
                     FT_Raster_Params*  params );

  FT_Error  FT_Get_PFR_Metrics( FT_Face    face,
                      FT_UInt   *aoutline_resolution,
                      FT_UInt   *ametrics_resolution,
                      FT_Fixed  *ametrics_x_scale,
                      FT_Fixed  *ametrics_y_scale );
  FT_Error  FT_Get_PFR_Kerning( FT_Face     face,
                      FT_UInt     left,
                      FT_UInt     right,
                      FT_Vector  *avector );

  FT_Error  FT_Get_PFR_Advance( FT_Face   face,
                      FT_UInt   gindex,
                      FT_Pos   *aadvance );

  FT_Renderer  FT_Get_Renderer( FT_Library       library,
                   FT_Glyph_Format  format );

  FT_Error  FT_Set_Renderer( FT_Library     library,
                   FT_Renderer    renderer,
                   FT_UInt        num_params,
                   FT_Parameter*  parameters );

  FT_Error  FT_New_Size( FT_Face   face,
               FT_Size*  size );

  FT_Error  FT_Done_Size( FT_Size  size );


  FT_Error  FT_Activate_Size( FT_Size  size );

  FT_UInt  FT_Get_Sfnt_Name_Count( FT_Face  face );

  FT_Error  FT_Get_Sfnt_Name( FT_Face       face,
                    FT_UInt       idx,
                    FT_SfntName  *aname );

  FT_Fixed  FT_Sin( FT_Angle  angle );

  FT_Fixed  FT_Cos( FT_Angle  angle );

  FT_Fixed  FT_Tan( FT_Angle  angle );

  FT_Angle  FT_Atan2( FT_Fixed  x,
            FT_Fixed  y );

  FT_Angle  FT_Angle_Diff( FT_Angle  angle1,
                 FT_Angle  angle2 );

  void  FT_Vector_Unit( FT_Vector*  vec,
                  FT_Angle    angle );

  void  FT_Vector_Rotate( FT_Vector*  vec,
                    FT_Angle    angle );

  FT_Fixed  FT_Vector_Length( FT_Vector*  vec );

  void  FT_Vector_Polarize( FT_Vector*  vec,
                      FT_Fixed   *length,
                      FT_Angle   *angle );

  void  FT_Vector_From_Polar( FT_Vector*  vec,
                        FT_Fixed    length,
                        FT_Angle    angle );

  FT_Error  FT_Get_WinFNT_Header( FT_Face               face,
                        FT_WinFNT_HeaderRec  *aheader );

  FT_Int  FT_Has_PS_Glyph_Names( FT_Face  face );

  FT_Error  FT_Get_PS_Font_Info( FT_Face          face,
                       PS_FontInfoRec  *afont_info );

  FT_Error  FT_Get_PS_Font_Private( FT_Face         face,
                                    PS_PrivateRec  *afont_private );

  void*  FT_Get_Sfnt_Table( FT_Face      face,
                     FT_Sfnt_Tag  tag );

  FT_Error  FT_Load_Sfnt_Table( FT_Face    face,
                      FT_ULong   tag,
                      FT_Long    offset,
                      FT_Byte*   buffer,
                      FT_ULong*  length );

  FT_Error  FT_Sfnt_Table_Info( FT_Face    face,
                      FT_UInt    table_index,
                      FT_ULong  *tag,
                      FT_ULong  *length );


  FT_Int  FT_Get_Charmap_Index( FT_CharMap  charmap );

  FT_Error  FT_Get_MM_Var( FT_Face      face,
                 FT_MM_Var*  *amaster );

  FT_Error  FT_Set_Var_Design_Coordinates( FT_Face    face,
                                 FT_UInt    num_coords,
                                 FT_Fixed*  coords );

  FT_Error  FT_Set_Var_Blend_Coordinates( FT_Face    face,
                                FT_UInt    num_coords,
                                FT_Fixed*  coords );

  FT_Error  FT_Stream_OpenLZW( FT_Stream  stream,
                     FT_Stream  source );


  FT_Error  FT_OpenType_Validate( FT_Face    face,
                        FT_UInt    validation_flags,
                        FT_Bytes  *BASE_table, 
                        FT_Bytes  *GDEF_table, 
                        FT_Bytes  *GPOS_table, 
                        FT_Bytes  *GSUB_table, 
                        FT_Bytes  *JSTF_table );


  void  FT_Bitmap_New( FT_Bitmap  *abitmap );

  FT_Error  FT_Bitmap_Copy( FT_Library        library,
                  const FT_Bitmap  *source,
                  FT_Bitmap        *target);

  FT_Error  FT_Bitmap_Embolden( FT_Library  library,
                      FT_Bitmap*  bitmap,
                      FT_Pos      xStrength,
                      FT_Pos      yStrength );

  FT_Error  FT_Bitmap_Convert( FT_Library        library,
                     const FT_Bitmap  *source,
                     FT_Bitmap        *target,
                     FT_Int            alignment );

  FT_Error  FT_Bitmap_Done( FT_Library  library,
                  FT_Bitmap  *bitmap );


  FT_Error  FT_Select_Size( FT_Face  face,
                  FT_Int   strike_index );

  FT_Error  FT_Request_Size( FT_Face          face,
                   FT_Size_Request  req );


  FT_Error  FT_Get_Track_Kerning( FT_Face    face,
                        FT_Fixed   point_size,
                        FT_Int     degree,
                        FT_Fixed*  akerning );

  FT_Error  FT_Get_SubGlyph_Info( FT_GlyphSlot  glyph,
                        FT_UInt       sub_index,
                        FT_Int       *p_index,
                        FT_UInt      *p_flags,
                        FT_Int       *p_arg1,
                        FT_Int       *p_arg2,
                        FT_Matrix    *p_transform );


  FT_Orientation  FT_Outline_Get_Orientation( FT_Outline*  outline );


  FT_TrueTypeEngineType  FT_Get_TrueType_Engine_Type( FT_Library  library );


  void  FT_OpenType_Free( FT_Face   face,
                    FT_Bytes  table );


  FT_StrokerBorder  FT_Outline_GetInsideBorder( FT_Outline*  outline );

  FT_StrokerBorder  FT_Outline_GetOutsideBorder( FT_Outline*  outline );

  FT_Error  FT_Stroker_New( FT_Library   library,
                  FT_Stroker  *astroker );

  void  FT_Stroker_Set( FT_Stroker           stroker,
                  FT_Fixed             radius,
                  FT_Stroker_LineCap   line_cap,
                  FT_Stroker_LineJoin  line_join,
                  FT_Fixed             miter_limit );

  void  FT_Stroker_Rewind( FT_Stroker  stroker );

  FT_Error  FT_Stroker_ParseOutline( FT_Stroker   stroker,
                           FT_Outline*  outline,
                           FT_Bool      opened );

  FT_Error  FT_Stroker_BeginSubPath( FT_Stroker  stroker,
                           FT_Vector*  to,
                           FT_Bool     open );

  FT_Error  FT_Stroker_EndSubPath( FT_Stroker  stroker );

  FT_Error  FT_Stroker_LineTo( FT_Stroker  stroker,
                     FT_Vector*  to );

  FT_Error  FT_Stroker_ConicTo( FT_Stroker  stroker,
                      FT_Vector*  control,
                      FT_Vector*  to );

  FT_Error  FT_Stroker_CubicTo( FT_Stroker  stroker,
                      FT_Vector*  control1,
                      FT_Vector*  control2,
                      FT_Vector*  to );

  FT_Error  FT_Stroker_GetBorderCounts( FT_Stroker        stroker,
                              FT_StrokerBorder  border,
                              FT_UInt          *anum_points,
                              FT_UInt          *anum_contours );

  void  FT_Stroker_ExportBorder( FT_Stroker        stroker,
                           FT_StrokerBorder  border,
                           FT_Outline*       outline );

  FT_Error  FT_Stroker_GetCounts( FT_Stroker  stroker,
                        FT_UInt    *anum_points,
                        FT_UInt    *anum_contours );

  void  FT_Stroker_Export( FT_Stroker   stroker,
                     FT_Outline*  outline );

  void  FT_Stroker_Done( FT_Stroker  stroker );

  FT_Error  FT_Glyph_Stroke( FT_Glyph    *pglyph,
                   FT_Stroker   stroker,
                   FT_Bool      destroy );

  FT_Error  FT_Glyph_StrokeBorder( FT_Glyph    *pglyph,
                         FT_Stroker   stroker,
                         FT_Bool      inside,
                         FT_Bool      destroy );

  FT_Int  FT_Get_Gasp( FT_Face  face,
               FT_UInt  ppem );

  FT_Error  FT_Library_SetLcdFilter( FT_Library    library,
                           FT_LcdFilter  filter );

  FT_Error FT_TrueTypeGX_Validate( FT_Face   face,
                          FT_UInt   validation_flags,
                          FT_Bytes* tables,
                          FT_UInt   table_length );

  void FT_TrueTypeGX_Free( FT_Face   face,
                      FT_Bytes  table );

  FT_Error FT_ClassicKern_Validate( FT_Face    face,
                           FT_UInt    validation_flags,
                           FT_Bytes  *ckern_table );

  void FT_ClassicKern_Free( FT_Face   face,
                       FT_Bytes  table );

  FT_Bool  FT_Face_CheckTrueTypePatents( FT_Face  face );

  FT_Bool  FT_Face_SetUnpatentedHinting( FT_Face  face,
                                FT_Bool  value );

  FT_Error  FTC_ImageCache_LookupScaler( FTC_ImageCache  cache,
                               FTC_Scaler      scaler,
                               FT_ULong        load_flags,
                               FT_UInt         gindex,
                               FT_Glyph       *aglyph,
                               FTC_Node       *anode );

  FT_Error  FTC_SBitCache_LookupScaler( FTC_SBitCache  cache,
                              FTC_Scaler     scaler,
                              FT_ULong       load_flags,
                              FT_UInt        gindex,
                              FTC_SBit      *sbit,
                              FTC_Node      *anode );

  FT_Long  FT_Get_CMap_Format( FT_CharMap  charmap );

  FT_UShort  FT_Get_FSType_Flags( FT_Face  face );

  FT_UInt  FT_Face_GetCharVariantIndex( FT_Face   face,
                               FT_ULong  charcode,
                               FT_ULong  variantSelector );

  FT_Int  FT_Face_GetCharVariantIsDefault( FT_Face   face,
                                   FT_ULong  charcode,
                                   FT_ULong  variantSelector );

  FT_UInt32*  FT_Face_GetVariantSelectors( FT_Face  face );

  FT_UInt32*  FT_Face_GetVariantsOfChar( FT_Face   face,
                             FT_ULong  charcode );

  FT_UInt32*  FT_Face_GetCharsOfVariant( FT_Face   face,
                             FT_ULong  variantSelector );

  FT_Error  FT_Get_Advance( FT_Face    face,
                  FT_UInt    gindex,
                  FT_Int32   load_flags,
                  FT_Fixed  *padvance );

  FT_Error  FT_Get_Advances( FT_Face    face,
                   FT_UInt    start,
                   FT_UInt    count,
                   FT_Int32   load_flags,
                   FT_Fixed  *padvances );

  FT_Error  FT_GlyphSlot_Own_Bitmap( FT_GlyphSlot  slot );

  FT_Error  FT_Get_CID_Registry_Ordering_Supplement( FT_Face       face,
                                           const char*  *registry,
                                           const char*  *ordering,
                                           FT_Int       *supplement);

  FT_Error  FT_Get_CID_Is_Internally_CID_Keyed( FT_Face   face,
                                      FT_Bool  *is_cid );

  FT_Error  FT_Get_CID_From_Glyph_Index( FT_Face   face,
                               FT_UInt   glyph_index,
                               FT_UInt  *cid );

  const char*  FT_Get_X11_Font_Format( FT_Face  face );

  FT_Error  FT_Library_SetLcdFilterWeights( FT_Library      library,
                                  unsigned char  *weights );

  FT_Error  FT_Reference_Library( FT_Library  library );

  FT_Error  FT_Reference_Face( FT_Face  face );

  FT_Long  FT_Get_PS_Font_Value( FT_Face       face,
                        PS_Dict_Keys  key,
                        FT_UInt       idx,
                        void         *value,
                        FT_Long       value_len );

  FT_Error FT_Outline_EmboldenXY( FT_Outline*  outline,
                         FT_Pos       xstrength,
                         FT_Pos       ystrength );

  FT_Error FT_Property_Set( FT_Library        library,
                   const FT_String*  module_name,
                   const FT_String*  property_name,
                   const void*       value );

  FT_Error FT_Property_Get( FT_Library        library,
                   const FT_String*  module_name,
                   const FT_String*  property_name,
                   void*             value );

#endif /* CLIB_FREETYPE_PROTOS_H */

