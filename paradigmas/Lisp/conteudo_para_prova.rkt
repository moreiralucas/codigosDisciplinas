#lang racket
; Contagem
(define (contagem n [a '()])
  (if (> n 0)
      (contagem (- n 1) (cons n a))
      a))

; Aplanar
(define (aplanar LG)
  (cond
    [(null? LG) LG]
    [(list? (first LG))
     (conc (aplanar (first LG)) (aplanar (rest LG)))]
    [else
     (cons (first LG)
           (aplanar (rest LG)))]))

; Aplanar
(define (aplanar LG)
  (cond
    [(null? LG) LG]
    [(list? (first LG))
     (conc (aplanar (first LG)) (aplanar (rest LG)))]
    [else
     (cons (first LG)
           (aplanar (rest LG)))]))

; Contagem crescente
(define (contagem n [a '()])
  (if (> n 0)
      (contagem (- n 1) (cons n a))
      a))

; Contagem decrescente
(define (contagem-dec m n [a '()])
  (if (< m n)
      (contagem-dec (+ m 1) n (cons (+ m 1) a))
      a))

; Concatenar l1 com l2
(define (conc l1 l2)
  (cond
    [(null? l1) l2]
    [(null? l2) l1]
    [else (cons (first l1) (conc (rest l1) l2))]
))

;(adiciona-1 '(1 2 3 4 5 6))
(define (adiciona-1 l)
  (map (lambda(x) (+ x 1)) l))

;#lang racket
(define (concatenar1 l1 l2)
  (cond
    [(null? l1) l2]
    [(null? l2) l1]
    [else (cons (first l1)
                (concatenar1(rest l1) l2))]))



(define (concatenarInv l1 l2)
  (cond
    [(null? l1) l2]
    [(null? l2) l1]
    [else (cons (first l2)
                (concatenarInv l1 (rest l2)))]))

(define (concatenar2 LL [l2 '()])
  (cond
    [(null? LL)l2]
    [else (concatenar1 (first LL)
          (concatenar2 (rest LL)l2))]))

(define (juntar l1 l2)
  (cond
    [(null? l1) l2]
    [(null? l2) l1]
    [else (cons (first l1)
          (juntar l2 (rest l1)))]))


(define (adicionarFinal e l1)
  (cond
    [(null? l1) (list e)]  
    [else (cons (first l1)
                (adicionarFinal e (rest l1)))]))

(define (myappend l1 l2)
	(cond
          [(null? l1) l2]
          [else (cons (first l1)
                      (myappend (rest l1) l2))]))
(define (inverter l1)
  (cond
    [(null? l1) '()]
    [else (myappend (inverter (rest l1))
                            (list (first l1)))]))

(define (parear e l1 [l2 '()])
  (cond
    [(null? l1) l2]
    [else 
                (parear e (cdr l1) (adicionarFinal (cons e (first l1)) l2))]))

(define (pares l1 [l2 '()])
  (cond
    [(null? l1) l2]
    [else (parear (first l1) (cdr l1) l2)
          (pares (rest l1) (parear (first l1) (cdr l1) l2))]))

(define (aux e l2)
  (cond
    [(null? l2) #F]
    [(eq? e (first l2)) #F]
    [else (conjunto (rest l2))]))
  
(define (conjunto l1)
  (cond
    [(null? l1) #T]
    [else (aux (first l1) (rest l1))]))

(define (prefixo l1 l2)
  (cond
    [(null? l1) #T]
    [(null? l2) #T]
    [(not (eq? (first l1) (first l2))) #F]
    [else (prefixo (rest l1) (rest l2))])) 
    
(define (subsequencia l1 l2)
  (cond
    [(null? l1) #T]
    [(not (eq? (first l1) (first l2))) (subsequencia l1 (rest l2))]
    [else (prefixo l1 l2)]))

;;PROVA 2014
;;questao 1
(define (intercala a b x [l2 '()])
  (cond
  [(<= x 0) l2]
  [else (cons a (intercala b a (- x 1) l2))]))

;;questao 2 e 3 auxs
;;retorna lista com caracteres repetidos
(define (aux2 e l1 [l2 '()])
  (cond
    [(null? l1) l2]
    [(not (eq? e (first l1)))l2]
    [else (aux2 (first l1) (rest l1) (cons e l2))]))
;;marca posicao
(define (pos1 e l1 [l2 '()]) 
  (cond
    [(null? l1) l1]
    [(not (eq? e (first l1))) l1]
    [else (pos1 (first l1) (rest l1) l2)]))

(define (empacote l1 [l2 '()])
  (cond
    [(null? l1) l2]
    [else (empacote (pos1 (first l1) l1 l2) (adicionarFinal (aux2 (first l1) l1) l2))]))
;;questao 3

(define (contaRepetidos a l1 [x 0])
        (cond
          [(null? l1) x]
          [(not (eq? a (first l1))) (contaRepetidos a (rest l1) x)]
          [else (contaRepetidos a (rest l1) (+ x 1))]))
(define (extrai e l1 [l2 '()])
  (cond
    [(null? l1) (list l2)]
    [(not(eq? e (first l1))) (cons l2 l1)]
    [else (extrai e (rest l1) (cons e l2))])) 

(define (codifica l [l2 '()])
   (cond
     [(null? l) l2]
     [else
      (cons
       (cons (extrai (first l)  l l2) (length (extrai(first l) l)))
        (codifica (rest(extrai (first l) l l2))))]))
;; questao 3 certa
(define (codificaCerto l [l2 '()])
  (codifica2(empacote l)))
(define (codifica2 l)
  (cond
  [(null? l)l]
  [else
   (cons
    (cons (first (first l)) (length (first l)))
    (codifica2 (rest l)))]))
;;PROVA 2015
;;questao 4 
(define (transforma f lg)
  (cond
   [(null? lg) lg]
   [(list? (first lg)) (cons (transforma f (first lg)) (transforma f (rest lg)))]
   [else
    (cons (f (first lg)) (transforma f (rest lg)))]))
;;questao 2
(define (aplanar l)
  (cond
    [(null? l) l]
    [(list? (first l))
     (append
      (aplanar(first l)) (aplanar (rest l)))] 
    [else (cons (first l)(aplanar(rest l)))]))

;;questao 1
(define (contagem x [l2 '()])
  (cond
    [(<= x 0) l2]
    [else
     (adicionarFinal x (contagem (- x 1) l2))]))
;;questao 3
(define (iguais l1 l2)
  (cond
    [(and (null? l1) (null? l2)) #T]
    [(null? l1) #F]
    [(null? l2) #F]
    [(and (list? (first l1)) (list? (first l2)) (iguais (first l1) (first l2)) (iguais (rest l1) (rest l2)))]
    [(and (list? (first l1)) (not (list? (first l2)))) #F]
    [(and (not(list? (first l1))) (list? (first l2))) #F]
    [(eq? (first l1) (first l2)) #T]
    [else
     (not (eq? (first l1) (first l2)))#F]))
;;questao teste lamoglia
(define (contagem2 n)
  (cond
    [(eq? n 1) (list n)]
    [else (adicionarFinal n (contagem2 (- n 1)))]
    ))
;;questao aplanar refeita
(define (aplanar2 l1)
  (cond
    [(null? l1) l1]
    [(list? first l1)
     (append (aplanar (first l1)) (aplanar (rest l1)))]
    [else
     (append (first l1) (aplanar rest l1))]))
;;questao transformar refeita
(define (transformers f l1)
  (cond
    [(null? l1)l1]
    [(list? l1)
     (append (transformers f (first l1)) (transformers f (rest l1)))]
    [else
     (cons (f (first l1)) (transformers f (rest l1)))]))
;;questao 5
(define (remove a l1 [l2 '()])
  (cond
    [(null? l1) l2]
    [(not (eq? a (first l1))) remove(a (remove a (rest l1)) l2)]
    [else
     (remove (first l1) (remove a (rest l1)) l2)]))
(define (removeSimilares l1)
  (cond
    [(null? l1) l1]
    [else (removeSimilares(remove (first l1) (rest l1)))]))
;;remove todos
(define (removeAll a l1)
  (cond
    [(null? l1) l1]
    [(eq? a (first l1)) (removeAll (first l1) (rest l1))]
    [else
     (cons (first l1) (removeAll a (rest l1)))]))
;; PROVA 2 2017
;;questao 1