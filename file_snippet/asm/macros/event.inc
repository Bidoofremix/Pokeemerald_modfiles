< //
	.macro bufferitemnameplural out:req, item:req, quantity:req
	.byte 0xe2
	.byte \out
	.2byte \item
	.2byte \quantity
	.endm

	.macro setmonball slot:req, item:req
	.byte 0xe3
	.2byte \slot
	.2byte \item
	.endm
	
	.macro setmonmetbreedersclub slot:req
	.byte 0xe4
	.2byte \slot
	.endm

	.macro questmenu case:req, questId:req
    .byte 0xe5
    .byte \case
    .byte \questId
    .endm
    
    .macro openquestmenu
    questmenu 0 0
    .endm

	
@ Supplementary
// >