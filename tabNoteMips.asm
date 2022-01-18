.data
fichier: .asciiz "notes.txt"
buffer:.float
.align 2
#note:.float
affiche:.asciiz "*"

.text	
lecture:
li   $v0, 13		#ouverture d'un fichier
la   $a0, fichier     
li   $a1, 0      
li   $a2, 0
syscall            
move $s1, $v0     

li   $v0, 14      	#lire un fichier
move $a0, $s1     
la   $a1, buffer
li   $a2, 150
syscall            

ori  $t0,$s1,0           #i
ori  $t1,$0,150		#taille du fichier
#la   $t2,note
sub  $sp,$sp,2		#allouer un float sur la pile

POUR:slt $t3,$t0,$t1 	
     beq $t3,$0,SUITE
     lh  $t4,0($s1)
     sh  $t4,0($sp)
     addi $t0,$t0,1
     addi $s1,$s1,2
     addi $sp,$sp,-2
     j POUR

SUITE:li   $v0, 16	#fermer un fihier
      move $a0, $s1     
      syscall          
      
tabNoteEleve:

ori $t6,$0,0		#min
ori $t5,$0,0		#i

FORi:slti $t6,$t5,149	
     beq $t8,$0,FINi
     lh  $t8,0($sp)
     j FORj
     addi $t5,$t5,1
     addi $sp,$sp,-1
     j FORi
     
ori $t7,$t5,0
addi $t7,$t7,1   
FORj:slti $t9,$t7,150	
     beq $t9,$0,FINj
     subi $sp,$sp,1
     j IF
     addi $t7,$t7,1	     

IF:lh $t0,0($sp)
   bge $t0,$t6,suite

suite:lw  $t0,0($sp)
      lw  $t6,0($sp)
      ori $t6,$t0,0
      jr $ra
      
FINj:jr $ra

FINi:add $a0,$0,$sp
     ori $v0,$0,1
     syscall
     

compteur:
ori $t0,$0,1		#compteur
ori $t1,$0,0		#i
sub  $fp,$fp,4

Boucle:slti $t2,$t1,150
       beq $t2,$0,FIN
       lh $t3,0($sp)
       j If
       addi $t1,$t1,1
       
If:addi $sp,$sp,2 
   lh $t4,0($sp)
   bne $t3,$t4,Else
   addi $t0,$t0,1
   
   
Else:sw $t0,0($fp)
     subi $fp,$fp,4
     j Boucle

FIN:jr $ra

ori $t0,$0,0		#j
ori $t3,$0,0		#k

Affichage:slti $t1,$t0,150
          beq $t1,$0,FINI
          lh $a0,0($sp)
          ori $v0,1
          syscall
          addi $sp,$sp,2  
          
Apres:lw $t2,0($fp)
      slt $t4,$t3,$t2
      beq $t4,$0,Fink
      ori $v0,4
      la $a0,affiche
      syscall
      addi $fp,$fp,4
      j Apres

Fink:addi $fp,$fp,4
     j Affichage
                             
FINI:ori $v0,10
     syscall

		
	





 



