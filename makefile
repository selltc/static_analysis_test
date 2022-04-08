default: structalloc.exe memcpy_test.exe memcpy_s_test.exe strncpy_s_test.exe leak.exe leak2.exe leak3.exe leak4.exe

structalloc.exe: structalloc.obj
	link /out:$@ structalloc.obj
memcpy_test.exe: memcpy_test.obj
	link /out:$@ memcpy_test.obj
memcpy_s_test.exe: memcpy_s_test.obj
	link /out:$@ memcpy_s_test.obj
strncpy_s_test.exe: strncpy_s_test.obj
	link /out:$@ strncpy_s_test.obj
leak.exe: leak.obj
	link /out:$@ leak.obj
leak2.exe: leak2.obj
	link /out:$@ leak2.obj
leak3.exe: leak3.obj
	link /out:$@ leak3.obj
leak4.exe: leak4.obj
	link /out:$@ leak4.obj



structalloc.obj: structalloc.c
	cl /c /W4 /analyze:WX- /FC structalloc.c
memcpy_test.obj: memcpy_test.c
	cl /c /W4 /analyze:WX- /FC memcpy_test.c
memcpy_s_test.obj: memcpy_s_test.c
	cl /c /W4 /analyze:WX- /FC memcpy_s_test.c
strncpy_s_test.obj: strncpy_s_test.c
	cl /c /W4 /analyze:WX- /FC strncpy_s_test.c
leak.obj: leak.c
	cl /c /W4 /analyze:WX- /FC leak.c
leak2.obj: leak2.c
	cl /c /W4 /analyze:WX- /FC leak2.c
leak3.obj: leak3.c
	cl /c /W4 /analyze:WX- /FC leak3.c
leak4.obj: leak4.c
	cl /c /W4 /analyze:WX- /FC leak4.c



clean:
	-del *~
	-del *.obj
	-del *.exe
	-del *.xml
