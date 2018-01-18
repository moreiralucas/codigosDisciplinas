#lang racket

(define l1 '(2 54 65 7 3 12 10))

(define l3 '(54 65 2 7 3 12 10))

(define l2 
  '((2 a) (5 dd d) (65) (12 2 2 2 2) (3 12 10 a)))

(define l4 
  '((2 3) (5 1) (65 0) (12 2) (3 12)))



;; Bubble Sort

(define (bubble-sort l #:fc [f <] #:key [c identity])
  (cond
    [(null? l) l]
    [else
     (let [(m (menor (first l) (rest l) #:fc f #:key c))]
       (cons (first m) (bubble-sort (rest m) #:fc f #:key c)))]
    ))
 

(define (menor m rl [nm '()] #:fc f #:key k)
  (cond
    [(null? rl) (cons m nm)]
    [(f (k (first rl)) (k m))
         (menor (first rl)
                (rest rl)
                (cons m nm)
                #:fc f
                #:key k)]
    [else (menor m 
                 (rest rl) 
                 (cons (first rl) nm)
                 #:fc f
                 #:key k)]
    ))


;; Insertion Sort

(define (insere e l)
  (cond
    [(null? l) (list e)]
    [(< e (first l)) (cons e l)]
    [else (cons (first l) (insere e (rest l)))]
  ))

(define (is l [lr '()])
  (cond
    [(null? l) lr]
    [else
        (is (rest l) (insere (first l) lr))]
    ))

;; Generic Insertion Sort 
;; Exemplo de chamada:
;; (isg '((2 2) (3 1) (1 1)) #:f >= #:key first)
(define (isg l [lr '()] #:f [f <] #:key [k identity])
  (cond
    [(null? l) lr]
    [else (isg (rest l)
               (insereg (first l) lr f k)
               #:f f
               #:key k)]
    ))

(define (insereg e l f k)
  (cond
    [(null? l) (list e)]
    [(f (k e) (k (first l))) (cons e l)]
    [else
       (cons (first l) (insereg e (rest l) f k))]
    ))
     
;; Merge Sort
;;
;;
(define (mescle l1 l2)
  (cond
    [(null? l1) l2]
    [(null? l2) l1]
    [(< (first l2) (first l1)) 
       (cons (first l2) (mescle l1 (rest l2)))]
    [else
       (cons (first l1) (mescle (rest l1) l2))]
    ))

(define (divide l [l1 '()] [l2 '()])
  (cond
    [(null? l) (cons l1 l2)]
    [else
       (divide (rest l) l2 (cons (first l) l1))]
    ))

(define (ms l)
  (cond
    [(null? l) l]
    [(null? (rest l)) l]
    [else
     (let ([dl (divide l)])
       (mescle
          (ms (first dl))
          (ms (rest dl))))]))
       