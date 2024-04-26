.code

public mult

mult proc
	movss xmm0, dword ptr [rsp + 4]
	movss xmm1, dword ptr [rsp + 8]

	mulss xmm0, xmm1

	ret
mult endp

end