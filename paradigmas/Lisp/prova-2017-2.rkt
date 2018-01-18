#lang racket
;Questão 1
(define (cria-camada i n)
  (if (> n 0)
      (cons (+ 1 i) (cria-camada (+ 1 i) (- n 1)))
      '()))
;(cria-camada 10 3)

;Questão 2
(define (cria-neuronios-aux l a)
  (cond
    [(null? l) l]
    [else (cons (cria-camada a (first l))
                (cria-neuronios-aux (rest l) (+ (first l) a))
           )
    ]
  )
)
(define (cria-neuronios l)
  (cria-neuronios-aux l '0))
;(cria-neuronios '(5 3 3))

;Rascunho
(define (ultimo l a)
  (cond
    [(null? l) a]
    [else (ultimo (rest l) (first l))]))
;(ultimo '(5 3 4) 0)

;Questão 3
(define (arcos-saida l e)
  (cond
    [(null? l) l]
    [else (cons (cons (first l) e)
                (arcos-saida (rest l) e))]
  )
)
;(arcos-saida '(8 9 10) 's)

;Questão 4
(define (arcos-intermediarios l1 l2)
  (cond
    [(null? l1) l1]
    [(null? l2) l2]
    [else (append (arcos-saida l1 (first l2))
                  (arcos-intermediarios l1 (rest l2)))]
    )
)
;(arcos-intermediarios '(1 2 3 4) '(5 6 7))

(define (crie-todas-conexoes ll)
  (cond
    [(null? ll) ll]
    [(null? ll) (rest ll) (arcos-saida ll 's)]
    [(list? (first ll)) (cons
                         (arcos-intermediarios (first ll))
                         (crie-todas-conexoes (rest ll)))]
    [else (arcos-intermediarios ll (crie-todas-conexoes (rest ll)))]
  )
)

;(crie-todas-conexoes (cria-neuronios '(4 3 3)))
(crie-todas-conexoes '((1 2 3 4) (5 6 7) (8 9 10)))