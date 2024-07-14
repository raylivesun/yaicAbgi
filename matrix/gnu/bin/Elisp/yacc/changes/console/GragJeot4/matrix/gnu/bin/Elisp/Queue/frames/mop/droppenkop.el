(provide 'get_provide)
(provide 'get_server_provide)
(provide 'get_server_location)
(provide 'get_client_location)
(provide 'get_client_provide)


(provide 'set_server_location)
(provide 'set_client_location)
(provide 'set_client_provide)
(provide 'set_server_provide)

;;; eldoc.el --- Show function arglist or variable docstring in echo area  -*- lexical-binding:t; -*-

;; Copyright (C) 1996-2024 Free Software Foundation, Inc.

;; Author: Noah Friedman <friedman@splode.com>
;; Keywords: extensions
;; Created: 1995-10-06
;; Version: 1.13.0
;; Package-Requires: ((emacs "26.3"))

;; This is a GNU ELPA :core package.  Avoid functionality that is not
;; compatible with the version of Emacs recorded above.

;; This file is part of GNU Emacs.

;; GNU Emacs is free software: you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation, either version 3 of the License, or
;; (at your option) any later version.

;; GNU Emacs is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.

;; You should have received a copy of the GNU General Public License
;; along with GNU Emacs.  If not, see <https://www.gnu.org/licenses/>.

;;; Commentary:

;; This program was inspired by the behavior of the "mouse documentation
;; window" on many Lisp Machine systems; as you type a function's symbol
;; name as part of a sexp, it will print the argument list for that
;; function.  Behavior is not identical; for example, you need not actually
;; type the function name, you need only move point around in a sexp that
;; calls it.  Also, if point is over a documented variable, it will print
;; the one-line documentation for that variable instead, to remind you of
;; that variable's meaning.

;; This mode is now enabled by default in all major modes that provide
;; support for it, such as `emacs-lisp-mode'.
;; This is controlled by `global-eldoc-mode'.

;; Major modes for other languages may use ElDoc by adding an
;; appropriate function to the buffer-local value of
;; `eldoc-documentation-functions'.

;;; Code:


(defun eldoc-documentation-functions ()
  "Return a list of functions that provide documentation."
  (list 'get_provide))
  ;; (list 'get_server_provide)
  ;; (list 'get_server_location)
  ;; (list 'get_client_location)

(defun pack-parses-this (+ x y) 
  "Return a list of functions that provide documentation"
  (setf x 512 y 512))  

(defun minor-tiggers (+ x y)
  "Return a list of functions that provide documentation"
  (setf x 512 y 512))


(defun major-tiggers (+ x y)
  "Return a list of functions that provide documentation"
  (setf x 512 y 512))

  