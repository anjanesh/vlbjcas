DECLARE SUB PrintOutput (FileNo AS INTEGER, LinesLeft AS INTEGER)
DIM i AS INTEGER
DIM SHARED OFile AS STRING, MaxLen AS INTEGER
DIM StartFileNo%, EndFileNo%
CLS
INPUT "Start : (Default = 1)", StartFileNo: IF StartFileNo = 0 THEN StartFileNo = 1
INPUT "End : (Default = 25)", EndFileNo: IF EndFileNo = 0 THEN EndFileNo = 25
INPUT "Max Lines to Print/Display (Default = 22)", MaxLen: IF MaxLen = 0 THEN MaxLen = 22
OFile$ = "k:\staff\makesh\01cs147\pract\output.txt"
FOR i = StartFileNo TO EndFileNo
IF i = 2 OR i = 21 THEN 10
CFile$ = "k:\staff\makesh\01cs147\pract\" + LTRIM$(STR$(i)) + ".c"
OPEN CFile$ FOR INPUT AS #1
 count = 0
 PRINT "Printing Page 1 of" + STR$(i) + ".c"
 LPRINT SPACE$(35) + STR$(i) + ".c"
 WHILE NOT EOF(1)
  LINE INPUT #1, lineCode$: count = count + 1
  IF count MOD MaxLen = 0 THEN
   Wt$ = INPUT$(1)
   IF Wt$ = CHR$(27) THEN END
   PRINT "Printing Page" + STR$((count / MaxLen) + 1) + " of" + STR$(i) + ".c"
   LPRINT SPACE$(35) + STR$(i) + ".c"
  END IF
  LPRINT lineCode$
 WEND
CLOSE #1
IF count MOD MaxLen <> 0 THEN Wt$ = INPUT$(1)
IF Wt$ = CHR$(27) THEN END
PrintOutput i, MaxLen - (count MOD MaxLen + 1)
10 NEXT i
END

SUB PrintOutput (FileNo AS INTEGER, LinesLeft AS INTEGER)
DIM LinesNeeded%, i%, count%
OPEN OFile$ FOR INPUT AS #1
DO: LINE INPUT #1, Marker$: LOOP UNTIL (LTRIM$(Marker$) = "Output" + STR$(FileNo)) OR EOF(1)
DO: LINE INPUT #1, Marker$: LinesNeeded = LinesNeeded + 1: LOOP UNTIL (LEFT$(LTRIM$(Marker$), 6) = "Output") OR EOF(1)
CLOSE #1
LinesNeeded = LinesNeeded - 2
OPEN OFile$ FOR INPUT AS #1
 DO: LINE INPUT #1, Marker$: LOOP UNTIL (LTRIM$(Marker$) = "Output" + STR$(FileNo)) OR EOF(1)
 PRINT "Printing Page 1 of Program Output" + STR$(FileNo)
 LPRINT : LPRINT "Program Output" + STR$(FileNo)
 FOR i = 1 TO LinesNeeded
  LINE INPUT #1, Marker$: LPRINT Marker$: count = count + 1
  IF count MOD MaxLen = 0 THEN
   Wt$ = INPUT$(1)
   IF Wt$ = CHR$(27) THEN END
   PRINT "Printing Page" + STR$((count / MaxLen) + 1) + " of Program Output" + STR$(FileNo)
   LPRINT "Program Output " + STR$(FileNo) + " (...contd)"
  END IF
 NEXT i
 CLOSE #1
Wt$ = INPUT$(1)
END SUB

