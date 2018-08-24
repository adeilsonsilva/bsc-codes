; Implemente a função (soma-lista lista), que retorna a soma dos elementos da lista.
(defun soma-lista-acum (lista acum)
	(cond
      ((null lista) acum)
      (t (soma-lista-acum (cdr lista) (+ acum (car lista))))
 	)
)

(defun soma-lista (lista)
  (soma-lista-acum (cdr lista) (car lista)))

(print (soma-lista '(1))) 	     ; 1
(print (soma-lista '(1 2 3))) 	 ; 6
(print (soma-lista '(10 10 10))) ; 10

; ======================================================================================================

; Implemente a função (fatorial n), que retorna o valor de n! (n fatorial).
(defun fatorial-acum (n acum)
	(cond
      ((null n) acum)
      (t (fatorial-acum (- n 1) (* acum n)))
 	)
)

(defun fatorial (n)
  (fatorial-acum (- n 1) n))

(print (fatorial '1))
(print (fatorial '2))
(print (fatorial '3))
(print (fatorial '4))
(print (fatorial '5))

; ======================================================================================================

; Implemente a função (fibonacci n), que retorna o n-ésimo número da sequência de Fibonacci.
(defun fibonacci-acum (n i j acum)
	(cond
      ((<= n 1) acum)
      (t (fibonacci-acum (- n 1) j acum (+ j acum)))
 	)
)

(defun fibonacci (n)
  (fibonacci-acum n 0 0 1))

					   ; (fibonacci-acum 1 1 2 3)) = 5
					   ; (fibonacci-acum 2 1 1 2)) = 3
					   ; (fibonacci-acum 3 0 1 1)) = 2
					   ; (fibonacci-acum 4 0 0 1)) = 1
(print (fibonacci '5)) ; (fibonacci-acum 5 0 0 1)) = 1

; ======================================================================================================

; Implemente a função (inverte lista), que retorna uma lista com os mesmos elementos do argumento,
; porém em ordem inversa. Exemplo: (inverte '(q w e)) ==> '(e w q).
(defun inverte-acum (lista acum)
	(cond
      ((null lista) acum)
      (t (inverte-acum (cdr lista) (cons (car lista) acum)))
 	)
)

(defun inverte (lista)
  (inverte-acum lista '()))

(print (inverte '(1 2 3)))
(print (inverte '(q w e)))

; ======================================================================================================

; Implemente a função (concatena l1 l2), que recebe duas listas, l1 e l2, e retorna uma lista com os elementos de l1
; na sequência, seguidos dos elementos de l2 na sequência. Exemplo: (concatena '(m u n) '(d o)) ==> '(m u n d o)
