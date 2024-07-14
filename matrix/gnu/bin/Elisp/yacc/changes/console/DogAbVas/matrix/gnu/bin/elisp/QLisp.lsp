(provide 'cat)
(provide 'myall)
(provide 'catnet)
(provide 'cakenet)
(provide 'soda)
(provide 'cl-lib)

;; ref definitions 
(xref-find-definitions 'ref)
;; specify the values variables
(setf x 512 y 512)
;; list numeric values of args test
(defun self-args (test-func args)
  "The lot series document self args view element"
  (funcall test-func args))
;; smile haver bird's vooboq c++ qt
(defun voo-boq (test-func args) 
  "The vooboq c++ qt documentation"
  (funcall (test-func args)))
;; open menu vooboq c++ qt emacs gnu menu
(voo-boq (list 1 2 3) (buffer-menu-open))
