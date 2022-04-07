default: structalloc.exe memcpy_test.exe memcpy_s_test.exe strncpy_s_test.exe

structalloc.exe: structalloc.obj
	link /out:$@ structalloc.obj
memcpy_test.exe: memcpy_test.obj
	link /out:$@ memcpy_test.obj
memcpy_s_test.exe: memcpy_s_test.obj
	link /out:$@ memcpy_s_test.obj
strncpy_s_test.exe: strncpy_s_test.obj
	link /out:$@ strncpy_s_test.obj



structalloc.obj: structalloc.c
	cl /c /W4 /analyze:WX- /FC structalloc.c
memcpy_test.obj: memcpy_test.c
	cl /c /W4 /analyze:WX- /FC memcpy_test.c
memcpy_s_test.obj: memcpy_s_test.c
	cl /c /W4 /analyze:WX- /FC memcpy_s_test.c
strncpy_s_test.obj: strncpy_s_test.c
	cl /c /W4 /analyze:WX- /FC strncpy_s_test.c



clean:
	-del *~
	-del *.obj
	-del *.exe
