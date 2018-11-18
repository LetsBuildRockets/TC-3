<?xml version='1.0'?>
<Project Type="Project" LVVersion="8508002">
   <Item Name="Mein Computer" Type="My Computer">
      <Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
      <Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
      <Property Name="server.tcp.enabled" Type="Bool">false</Property>
      <Property Name="server.tcp.port" Type="Int">0</Property>
      <Property Name="server.tcp.serviceName" Type="Str">Mein Computer/VI-Server</Property>
      <Property Name="server.tcp.serviceName.default" Type="Str">Mein Computer/VI-Server</Property>
      <Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
      <Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
      <Property Name="specify.custom.address" Type="Bool">false</Property>
      <Item Name="libpqlv" Type="Folder">
         <Item Name="lib" Type="Folder">
            <Item Name="comerr32.dll" Type="Document" URL="libpqlv/lib/comerr32.dll"/>
            <Item Name="libpq.dll" Type="Document" URL="libpqlv/lib/libpq.dll"/>
         </Item>
         <Item Name="src" Type="Folder"/>
         <Item Name="libpqlv.aliases" Type="Document" URL="libpqlv/libpqlv.aliases"/>
         <Item Name="libpqlv.lvlib" Type="Library" URL="libpqlv/libpqlv.lvlib"/>
         <Item Name="libpqlv.lvproj" Type="Document" URL="libpqlv/libpqlv.lvproj"/>
      </Item>
      <Item Name="libpqUtility" Type="Folder">
         <Item Name="src" Type="Folder"/>
         <Item Name="libpqutility.aliases" Type="Document" URL="libpqUtility/libpqutility.aliases"/>
         <Item Name="libpqutility.lvlib" Type="Library" URL="libpqUtility/libpqutility.lvlib"/>
         <Item Name="libpqutility.lvproj" Type="Document" URL="libpqUtility/libpqutility.lvproj"/>
      </Item>
      <Item Name="Abhängigkeiten" Type="Dependencies">
         <Item Name="vi.lib" Type="Folder">
            <Item Name="Merge Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Merge Errors.vi"/>
            <Item Name="Dflt Data Dir.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Dflt Data Dir.vi"/>
            <Item Name="Open Config Data.vi" Type="VI" URL="/&lt;vilib&gt;/UTILITY/config.llb/Open Config Data.vi"/>
            <Item Name="Config Data RefNum" Type="Document" URL="/&lt;vilib&gt;/Utility/config.llb/Config Data RefNum"/>
            <Item Name="Config Data Open Reference.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Config Data Open Reference.vi"/>
            <Item Name="Config Data Registry Functions.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Config Data Registry Functions.ctl"/>
            <Item Name="Config Data Registry.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Config Data Registry.vi"/>
            <Item Name="Config Data.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Config Data.ctl"/>
            <Item Name="Config Data Section.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Config Data Section.ctl"/>
            <Item Name="Config Data Set File Path.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Config Data Set File Path.vi"/>
            <Item Name="Config Data Modify Functions.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Config Data Modify Functions.ctl"/>
            <Item Name="Config Data Modify.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Config Data Modify.vi"/>
            <Item Name="Trim Whitespace.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Trim Whitespace.vi"/>
            <Item Name="whitespace.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/whitespace.ctl"/>
            <Item Name="Add Quotes.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Add Quotes.vi"/>
            <Item Name="Info From Config Data.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Info From Config Data.vi"/>
            <Item Name="Config Data Read From File.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Config Data Read From File.vi"/>
            <Item Name="Config Data Get File Path.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Config Data Get File Path.vi"/>
            <Item Name="String to Config Data.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/String to Config Data.vi"/>
            <Item Name="Invalid Config Data Reference.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Invalid Config Data Reference.vi"/>
            <Item Name="Config Data Close Reference.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Config Data Close Reference.vi"/>
            <Item Name="Write Key.vi" Type="VI" URL="/&lt;vilib&gt;/UTILITY/config.llb/Write Key.vi"/>
            <Item Name="Write Key (Boolean).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Write Key (Boolean).vi"/>
            <Item Name="Write Key (Double).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Write Key (Double).vi"/>
            <Item Name="Write Key (I32).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Write Key (I32).vi"/>
            <Item Name="Write Key (Path).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Write Key (Path).vi"/>
            <Item Name="Specific Path to Common Path.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Specific Path to Common Path.vi"/>
            <Item Name="Write Key (String).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Write Key (String).vi"/>
            <Item Name="Single to Double Backslash.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Single to Double Backslash.vi"/>
            <Item Name="Remove Unprintable Chars.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Remove Unprintable Chars.vi"/>
            <Item Name="Write Key (U32).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Write Key (U32).vi"/>
            <Item Name="Close Config Data.vi" Type="VI" URL="/&lt;vilib&gt;/UTILITY/config.llb/Close Config Data.vi"/>
            <Item Name="Config Data Write To File.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Config Data Write To File.vi"/>
            <Item Name="Config Data to String.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Config Data to String.vi"/>
            <Item Name="Error Cluster From Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Cluster From Error Code.vi"/>
            <Item Name="Read Key.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Read Key.vi"/>
            <Item Name="Read Key (Boolean).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Read Key (Boolean).vi"/>
            <Item Name="Config Data Get Key Value.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Config Data Get Key Value.vi"/>
            <Item Name="Read Key (Double).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Read Key (Double).vi"/>
            <Item Name="Read Key (I32).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Read Key (I32).vi"/>
            <Item Name="Read Key (Path).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Read Key (Path).vi"/>
            <Item Name="Remove Quotes.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Remove Quotes.vi"/>
            <Item Name="Common Path to Specific Path.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Common Path to Specific Path.vi"/>
            <Item Name="Read Key (String).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Read Key (String).vi"/>
            <Item Name="Parse Stored String.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Parse Stored String.vi"/>
            <Item Name="Get Next Character.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Get Next Character.vi"/>
            <Item Name="Read Key (U32).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/Read Key (U32).vi"/>
         </Item>
         <Item Name="GetDBConnectionsStringFromConfig.vi" Type="VI" URL="../MoSDeP1/src/GetDBConnectionsStringFromConfig.vi"/>
      </Item>
      <Item Name="Build-Spezifikationen" Type="Build">
         <Item Name="Meine DLL" Type="DLL">
            <Property Name="App_applicationGUID" Type="Str">{7837668F-ED4E-411B-8BEE-608FA21FC4B2}</Property>
            <Property Name="App_applicationName" Type="Str">SharedLib.dll</Property>
            <Property Name="App_companyName" Type="Str">fhe</Property>
            <Property Name="App_fileDescription" Type="Str">Meine DLL</Property>
            <Property Name="App_fileType" Type="Int">1</Property>
            <Property Name="App_fileVersion.major" Type="Int">1</Property>
            <Property Name="App_INI_aliasGUID" Type="Str">{3BF755C4-BC3B-4516-A9B3-3AE48811848C}</Property>
            <Property Name="App_INI_GUID" Type="Str">{CCF9EC4E-FC81-48CA-AE68-436BF0B81369}</Property>
            <Property Name="App_internalName" Type="Str">Meine DLL</Property>
            <Property Name="App_legalCopyright" Type="Str">Urheberrechte 2008 fhe</Property>
            <Property Name="App_productName" Type="Str">libpqlv</Property>
            <Property Name="Bld_buildSpecName" Type="Str">Meine DLL</Property>
            <Property Name="Bld_defaultLanguage" Type="Str">German</Property>
            <Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
            <Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
            <Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
            <Property Name="Destination[0].destName" Type="Str">SharedLib.dll</Property>
            <Property Name="Destination[0].path" Type="Path">../NI_AB_PROJECTNAME/bin/libpqlv/internal.llb</Property>
            <Property Name="Destination[0].type" Type="Str">App</Property>
            <Property Name="Destination[1].destName" Type="Str">Hilfsdatei-Verzeichnis</Property>
            <Property Name="Destination[1].path" Type="Path">../NI_AB_PROJECTNAME/bin/libpqlv/data</Property>
            <Property Name="DestinationCount" Type="Int">2</Property>
            <Property Name="Dll_delayOSMsg" Type="Bool">true</Property>
            <Property Name="Dll_headerGUID" Type="Str">{DCD48969-F728-40FF-8130-E057B17B8873}</Property>
            <Property Name="Dll_libGUID" Type="Str">{A158D0BC-EA8B-4E54-ADEE-D448FD9C00AB}</Property>
            <Property Name="Source[0].itemID" Type="Str">{100A819C-4BBF-44EF-8E38-C305F9626568}</Property>
            <Property Name="Source[0].type" Type="Str">Container</Property>
            <Property Name="Source[1].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[1].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/LargeObjects/lo close.vi</Property>
            <Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[1].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[10].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[10].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/LargeObjects/lo unlink.vi</Property>
            <Property Name="Source[10].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[10].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[100].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[100].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/DatabaseConnectionControlFunctions/PQconnectPoll.vi</Property>
            <Property Name="Source[100].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[100].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[101].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[101].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/AsynchronousCommandProcessing/PQsendQuery.vi</Property>
            <Property Name="Source[101].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[101].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[102].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[102].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/ConnectionStatusFunctions/PQserverVersion.vi</Property>
            <Property Name="Source[102].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[102].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[103].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[103].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/DatabaseConnectionControlFunctions/PQsetClientEncoding.vi</Property>
            <Property Name="Source[103].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[103].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[104].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[104].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/ControlFuntions/PQsetErrorVerbosity.vi</Property>
            <Property Name="Source[104].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[104].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[105].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[105].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/NoticeProcessing/PQsetNoticeReceiver.vi</Property>
            <Property Name="Source[105].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[105].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[106].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[106].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/NoticeProcessing/PQsetNoticeProcessor.vi</Property>
            <Property Name="Source[106].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[106].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[107].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[107].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/DatabaseConnectionControlFunctions/PQsetdbLogin.vi</Property>
            <Property Name="Source[107].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[107].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[108].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[108].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/AsynchronousCommandProcessing/PQsetnonblocking.vi</Property>
            <Property Name="Source[108].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[108].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[109].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[109].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/DatabaseConnectionControlFunctions/PQconnectStart.vi</Property>
            <Property Name="Source[109].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[109].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[11].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[11].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/LargeObjects/lo write.vi</Property>
            <Property Name="Source[11].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[11].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[12].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[12].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/ConnectionStatusFunctions/PQbackendPID.vi</Property>
            <Property Name="Source[12].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[12].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[13].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[13].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingQueryResultInformation/PQbinaryTuples.vi</Property>
            <Property Name="Source[13].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[13].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[14].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[14].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CancellingQueriesInProgress/PQcancel.vi</Property>
            <Property Name="Source[14].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[14].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[15].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[15].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/MainFunctions/PQclear.vi</Property>
            <Property Name="Source[15].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[15].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[16].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[16].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/DatabaseConnectionControlFunctions/PQclientEncoding.vi</Property>
            <Property Name="Source[16].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[16].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[17].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[17].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingResultInformationForOtherCommands/PQcmdTuples.vi</Property>
            <Property Name="Source[17].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[17].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[18].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[18].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/DatabaseConnectionControlFunctions/PQconndefaults.vi</Property>
            <Property Name="Source[18].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[18].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[19].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[19].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/DatabaseConnectionControlFunctions/PQconnectdb.vi</Property>
            <Property Name="Source[19].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[19].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[2].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[2].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/LargeObjects/lo creat.vi</Property>
            <Property Name="Source[2].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[2].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[20].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[20].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/DatabaseConnectionControlFunctions/PQconninfoFree.vi</Property>
            <Property Name="Source[20].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[20].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[21].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[21].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/AsynchronousCommandProcessing/PQconsumeInput.vi</Property>
            <Property Name="Source[21].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[21].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[22].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[22].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/ConnectionStatusFunctions/PQdb.vi</Property>
            <Property Name="Source[22].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[22].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[23].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[23].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/MainFunctions/PQdescribePortal.vi</Property>
            <Property Name="Source[23].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[23].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[24].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[24].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/MainFunctions/PQdescribePrepared.vi</Property>
            <Property Name="Source[24].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[24].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[25].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[25].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/MiscellaneousFuncitons/PQdsplen.vi</Property>
            <Property Name="Source[25].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[25].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[26].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[26].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/MiscellaneousFuncitons/PQencryptPassword.vi</Property>
            <Property Name="Source[26].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[26].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[27].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[27].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/MiscellaneousFuncitons/PQenv2encoding.vi</Property>
            <Property Name="Source[27].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[27].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[28].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[28].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/ConnectionStatusFunctions/PQerrorMessage.vi</Property>
            <Property Name="Source[28].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[28].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[29].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[29].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/EscapingBinaryStringsForInclusionInSQLCommands/PQescapeByteaConn.vi</Property>
            <Property Name="Source[29].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[29].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[3].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[3].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/LargeObjects/lo create.vi</Property>
            <Property Name="Source[3].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[3].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[30].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[30].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/EscapingBinaryStringsForInclusionInSQLCommands/PQescapeBytea.vi</Property>
            <Property Name="Source[30].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[30].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[31].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[31].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/EscapingResultInformationInSQLCommands/PQescapeStringConn.vi</Property>
            <Property Name="Source[31].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[31].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[32].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[32].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/EscapingResultInformationInSQLCommands/PQescapeString.vi</Property>
            <Property Name="Source[32].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[32].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[33].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[33].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/MainFunctions/PQexecParams.vi</Property>
            <Property Name="Source[33].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[33].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[34].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[34].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/MainFunctions/PQexecPrepared.vi</Property>
            <Property Name="Source[34].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[34].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[35].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[35].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/MainFunctions/PQexec.vi</Property>
            <Property Name="Source[35].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[35].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[36].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[36].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingQueryResultInformation/PQfformat.vi</Property>
            <Property Name="Source[36].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[36].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[37].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[37].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/DatabaseConnectionControlFunctions/PQfinish.vi</Property>
            <Property Name="Source[37].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[37].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[38].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[38].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/AsynchronousCommandProcessing/PQflush.vi</Property>
            <Property Name="Source[38].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[38].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[39].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[39].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingQueryResultInformation/PQfmod.vi</Property>
            <Property Name="Source[39].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[39].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[4].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[4].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/LargeObjects/lo export.vi</Property>
            <Property Name="Source[4].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[4].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[40].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[40].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingQueryResultInformation/PQfname.vi</Property>
            <Property Name="Source[40].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[40].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[41].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[41].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingQueryResultInformation/PQfnumber.vi</Property>
            <Property Name="Source[41].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[41].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[42].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[42].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CancellingQueriesInProgress/PQfreeCancel.vi</Property>
            <Property Name="Source[42].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[42].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[43].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[43].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/EscapingBinaryStringsForInclusionInSQLCommands/PQfreemem.vi</Property>
            <Property Name="Source[43].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[43].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[44].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[44].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingQueryResultInformation/PQfsize.vi</Property>
            <Property Name="Source[44].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[44].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[45].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[45].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingQueryResultInformation/PQftable.vi</Property>
            <Property Name="Source[45].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[45].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[46].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[46].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingQueryResultInformation/PQftablecol.vi</Property>
            <Property Name="Source[46].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[46].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[47].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[47].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingQueryResultInformation/PQftype.vi</Property>
            <Property Name="Source[47].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[47].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[48].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[48].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CancellingQueriesInProgress/PQgetCancel.vi</Property>
            <Property Name="Source[48].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[48].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[49].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[49].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/FunctionsAssociatedWithCOPYCommand/PQgetCopyData.vi</Property>
            <Property Name="Source[49].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[49].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[5].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[5].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/LargeObjects/lo import.vi</Property>
            <Property Name="Source[5].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[5].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[50].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[50].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/AsynchronousCommandProcessing/PQgetResult.vi</Property>
            <Property Name="Source[50].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[50].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[51].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[51].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingQueryResultInformation/PQgetisnull.vi</Property>
            <Property Name="Source[51].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[51].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[52].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[52].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingQueryResultInformation/PQgetlength.vi</Property>
            <Property Name="Source[52].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[52].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[53].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[53].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/ConnectionStatusFunctions/PQgetssl.vi</Property>
            <Property Name="Source[53].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[53].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[54].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[54].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingQueryResultInformation/PQgetvalue.vi</Property>
            <Property Name="Source[54].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[54].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[55].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[55].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/ConnectionStatusFunctions/PQhost.vi</Property>
            <Property Name="Source[55].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[55].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[56].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[56].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/sslSuport/PQinitSSL.vi</Property>
            <Property Name="Source[56].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[56].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[57].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[57].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/AsynchronousCommandProcessing/PQisBusy.vi</Property>
            <Property Name="Source[57].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[57].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[58].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[58].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/AsynchronousCommandProcessing/PQisnonblocking.vi</Property>
            <Property Name="Source[58].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[58].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[59].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[59].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/BehaviorInThreadedPrograms/PQisthreadsafe.vi</Property>
            <Property Name="Source[59].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[59].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[6].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[6].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/LargeObjects/lo lseek.vi</Property>
            <Property Name="Source[6].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[6].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[60].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[60].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/MainFunctions/PQmakeEmptyPGresult.vi</Property>
            <Property Name="Source[60].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[60].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[61].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[61].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/MiscellaneousFuncitons/PQmblen.vi</Property>
            <Property Name="Source[61].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[61].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[62].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[62].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingQueryResultInformation/PQnfields.vi</Property>
            <Property Name="Source[62].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[62].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[63].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[63].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/AsynchronousNotification/PQnotifies.vi</Property>
            <Property Name="Source[63].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[63].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[64].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[64].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingQueryResultInformation/PQnparams.vi</Property>
            <Property Name="Source[64].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[64].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[65].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[65].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingQueryResultInformation/PQntuples.vi</Property>
            <Property Name="Source[65].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[65].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[66].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[66].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingResultInformationForOtherCommands/PQoidStatus.vi</Property>
            <Property Name="Source[66].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[66].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[67].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[67].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingResultInformationForOtherCommands/PQoidValue.vi</Property>
            <Property Name="Source[67].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[67].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[68].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[68].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/ConnectionStatusFunctions/PQoptions.vi</Property>
            <Property Name="Source[68].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[68].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[69].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[69].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/ConnectionStatusFunctions/PQparameterStatus.vi</Property>
            <Property Name="Source[69].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[69].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[7].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[7].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/LargeObjects/lo open.vi</Property>
            <Property Name="Source[7].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[7].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[70].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[70].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingQueryResultInformation/PQparamtype.vi</Property>
            <Property Name="Source[70].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[70].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[71].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[71].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/ConnectionStatusFunctions/PQpass.vi</Property>
            <Property Name="Source[71].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[71].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[72].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[72].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/ConnectionStatusFunctions/PQport.vi</Property>
            <Property Name="Source[72].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[72].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[73].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[73].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/MainFunctions/PQprepare.vi</Property>
            <Property Name="Source[73].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[73].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[74].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[74].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingQueryResultInformation/PQprint.vi</Property>
            <Property Name="Source[74].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[74].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[75].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[75].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/ConnectionStatusFunctions/PQprotocolVersion.vi</Property>
            <Property Name="Source[75].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[75].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[76].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[76].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/FunctionsAssociatedWithCOPYCommand/PQputCopyData.vi</Property>
            <Property Name="Source[76].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[76].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[77].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[77].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/FunctionsAssociatedWithCOPYCommand/PQputCopyEnd.vi</Property>
            <Property Name="Source[77].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[77].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[78].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[78].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/BehaviorInThreadedPrograms/PQregisterThreadLock.vi</Property>
            <Property Name="Source[78].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[78].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[79].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[79].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CancellingQueriesInProgress/PQrequestCancel.vi</Property>
            <Property Name="Source[79].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[79].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[8].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[8].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/LargeObjects/lo read.vi</Property>
            <Property Name="Source[8].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[8].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[80].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[80].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/MainFunctions/PQresStatus.vi</Property>
            <Property Name="Source[80].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[80].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[81].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[81].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/DatabaseConnectionControlFunctions/PQresetPoll.vi</Property>
            <Property Name="Source[81].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[81].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[82].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[82].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/DatabaseConnectionControlFunctions/PQresetStart.vi</Property>
            <Property Name="Source[82].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[82].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[83].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[83].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/DatabaseConnectionControlFunctions/PQreset.vi</Property>
            <Property Name="Source[83].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[83].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[84].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[84].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/MainFunctions/PQresultErrorField.vi</Property>
            <Property Name="Source[84].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[84].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[85].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[85].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/MainFunctions/PQresultErrorMessage.vi</Property>
            <Property Name="Source[85].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[85].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[86].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[86].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/MainFunctions/PQresultStatus.vi</Property>
            <Property Name="Source[86].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[86].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[87].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[87].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/AsynchronousCommandProcessing/PQsendDescribePortal.vi</Property>
            <Property Name="Source[87].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[87].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[88].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[88].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/AsynchronousCommandProcessing/PQsendDescribePrepared.vi</Property>
            <Property Name="Source[88].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[88].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[89].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[89].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/AsynchronousCommandProcessing/PQsendPrepare.vi</Property>
            <Property Name="Source[89].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[89].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[9].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[9].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/LargeObjects/lo tell.vi</Property>
            <Property Name="Source[9].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[9].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[90].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[90].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/AsynchronousCommandProcessing/PQsendQueryParams.vi</Property>
            <Property Name="Source[90].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[90].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[91].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[91].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/AsynchronousCommandProcessing/PQsendQueryPrepared.vi</Property>
            <Property Name="Source[91].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[91].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[92].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[92].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/ConnectionStatusFunctions/PQsocket.vi</Property>
            <Property Name="Source[92].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[92].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[93].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[93].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/ConnectionStatusFunctions/PQstatus.vi</Property>
            <Property Name="Source[93].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[93].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[94].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[94].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/ConnectionStatusFunctions/PQtransaction Status.vi</Property>
            <Property Name="Source[94].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[94].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[95].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[95].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/ConnectionStatusFunctions/PQtty.vi</Property>
            <Property Name="Source[95].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[95].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[96].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[96].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/EscapingBinaryStringsForInclusionInSQLCommands/PQunescapeBytea.vi</Property>
            <Property Name="Source[96].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[96].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[97].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[97].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/ControlFuntions/PQuntrace.vi</Property>
            <Property Name="Source[97].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[97].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[98].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[98].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/ConnectionStatusFunctions/PQuser.vi</Property>
            <Property Name="Source[98].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[98].type" Type="Str">ExportedVI</Property>
            <Property Name="Source[99].destinationIndex" Type="Int">0</Property>
            <Property Name="Source[99].itemID" Type="Ref">/Mein Computer/libpqlv/libpqlv.lvlib/CommandExecutionFunctions/RetrievingResultInformationForOtherCommands/PQcmdStatus.vi</Property>
            <Property Name="Source[99].sourceInclusion" Type="Str">TopLevel</Property>
            <Property Name="Source[99].type" Type="Str">ExportedVI</Property>
            <Property Name="SourceCount" Type="Int">110</Property>
         </Item>
      </Item>
   </Item>
</Project>
