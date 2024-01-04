	.text
	.file	"templatet.cpp"
	.globl	_Z3addii                        # -- Begin function _Z3addii
	.p2align	4, 0x90
	.type	_Z3addii,@function
_Z3addii:                               # @_Z3addii
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	addl	-8(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	_Z3addii, .Lfunc_end0-_Z3addii
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3                               # -- Begin function main
.LCPI1_0:
	.quad	0x400b1eb851eb851f              # double 3.3900000000000001
	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$3, %edi
	callq	_Z7MystestIiET_S0_
	movl	%eax, -24(%rbp)
	movsd	.LCPI1_0(%rip), %xmm0           # xmm0 = mem[0],zero
	callq	_Z7MystestIdET_S0_
	movsd	%xmm0, -32(%rbp)
	movl	-20(%rbp), %edi
	callq	_Z7MystestIjET_S0_
	xorl	%eax, %eax
	addq	$32, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.section	.text._Z7MystestIiET_S0_,"axG",@progbits,_Z7MystestIiET_S0_,comdat
	.weak	_Z7MystestIiET_S0_              # -- Begin function _Z7MystestIiET_S0_
	.p2align	4, 0x90
	.type	_Z7MystestIiET_S0_,@function
_Z7MystestIiET_S0_:                     # @_Z7MystestIiET_S0_
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	addl	$789, %eax                      # imm = 0x315
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end2:
	.size	_Z7MystestIiET_S0_, .Lfunc_end2-_Z7MystestIiET_S0_
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3                               # -- Begin function _Z7MystestIdET_S0_
.LCPI3_0:
	.quad	0x4088a80000000000              # double 789
	.section	.text._Z7MystestIdET_S0_,"axG",@progbits,_Z7MystestIdET_S0_,comdat
	.weak	_Z7MystestIdET_S0_
	.p2align	4, 0x90
	.type	_Z7MystestIdET_S0_,@function
_Z7MystestIdET_S0_:                     # @_Z7MystestIdET_S0_
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movsd	%xmm0, -8(%rbp)
	movsd	.LCPI3_0(%rip), %xmm0           # xmm0 = mem[0],zero
	addsd	-8(%rbp), %xmm0
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end3:
	.size	_Z7MystestIdET_S0_, .Lfunc_end3-_Z7MystestIdET_S0_
	.cfi_endproc
                                        # -- End function
	.section	.text._Z7MystestIjET_S0_,"axG",@progbits,_Z7MystestIjET_S0_,comdat
	.weak	_Z7MystestIjET_S0_              # -- Begin function _Z7MystestIjET_S0_
	.p2align	4, 0x90
	.type	_Z7MystestIjET_S0_,@function
_Z7MystestIjET_S0_:                     # @_Z7MystestIjET_S0_
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	addl	$789, %eax                      # imm = 0x315
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end4:
	.size	_Z7MystestIjET_S0_, .Lfunc_end4-_Z7MystestIjET_S0_
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 14.0.0-1ubuntu1.1"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym _Z7MystestIiET_S0_
	.addrsig_sym _Z7MystestIdET_S0_
	.addrsig_sym _Z7MystestIjET_S0_
