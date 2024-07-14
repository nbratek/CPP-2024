Dear Student,

I'm happy to announce that you've managed to get **16** out of 16 points for this assignment.

There still exist some issues that should be addressed before the deadline: **2024-06-19 23:50:00 CEST (+0200)**. For further details, please refer to the following list:

<details><summary>Flawfinder znalazł potencjalne problemy z bezpieczeństwem kodu (to narzędzie może się pomylić)</summary>/tmp/tmpcxv2oyd7/student/mySorting.h:19:13:&nbsp;&nbsp;[4]&nbsp;(buffer)&nbsp;strcpy:Does&nbsp;not&nbsp;check&nbsp;for&nbsp;buffer&nbsp;overflows&nbsp;when&nbsp;copying&nbsp;to&nbsp;destination&nbsp;[MS-banned]&nbsp;(CWE-120).&nbsp;&nbsp;Consider&nbsp;using&nbsp;snprintf,&nbsp;strcpy_s,&nbsp;or&nbsp;strlcpy&nbsp;(warning:&nbsp;strncpy&nbsp;easily&nbsp;misused).&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;strcpy(str1,&nbsp;array[j]);<br>/tmp/tmpcxv2oyd7/student/mySorting.h:20:13:&nbsp;&nbsp;[4]&nbsp;(buffer)&nbsp;strcpy:Does&nbsp;not&nbsp;check&nbsp;for&nbsp;buffer&nbsp;overflows&nbsp;when&nbsp;copying&nbsp;to&nbsp;destination&nbsp;[MS-banned]&nbsp;(CWE-120).&nbsp;&nbsp;Consider&nbsp;using&nbsp;snprintf,&nbsp;strcpy_s,&nbsp;or&nbsp;strlcpy&nbsp;(warning:&nbsp;strncpy&nbsp;easily&nbsp;misused).&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;strcpy(str2,&nbsp;array[j&nbsp;+&nbsp;1]);<br>/tmp/tmpcxv2oyd7/student/mySorting.h:18:13:&nbsp;&nbsp;[2]&nbsp;(buffer)&nbsp;char:Statically-sized&nbsp;arrays&nbsp;can&nbsp;be&nbsp;improperly&nbsp;restricted,&nbsp;leading&nbsp;to&nbsp;potential&nbsp;overflows&nbsp;or&nbsp;other&nbsp;issues&nbsp;(CWE-119!/CWE-120).&nbsp;&nbsp;Perform&nbsp;bounds&nbsp;checking,&nbsp;use&nbsp;functions&nbsp;that&nbsp;limit&nbsp;length,&nbsp;or&nbsp;ensure&nbsp;that&nbsp;the&nbsp;size&nbsp;is&nbsp;larger&nbsp;than&nbsp;the&nbsp;maximum&nbsp;possible&nbsp;length.&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;char&nbsp;str1[size2],&nbsp;str2[size2];<br></details>

-----------
I remain your faithful servant\
_Bobot_\
_May 30, AD 2024, 08:42:59 (UTC)_