;; program name
;; program version
;; program copyright
;; program license
;; program authors
;; program contributors
;; program description
;; program dependencies


(in-package :cl-user)

(defpackage #:cl-user
  (:use :cl :cl-user)
  (:export #:cl-user))
  (in-package #:cl-user)

(defvar *program-name*
   "The name of the program.")
(defvar *program-version*
   "The version of the program.")
(defvar *program-copyright*
   "The copyright statement of the program.")
(defvar *program-license*
   "The license statement of the program.")
(defvar *program-authors*
   "The authors of the program.")
(defvar *program-contributors*
   "The contributors of the program.")
(defvar *program-description*
   "The description of the program.")
(defvar *program-dependencies*
   "The dependencies of the program.")


(defun cl-user-program-name ()
  *program-name*)
  (setf *program-name* "New program name"))
  (defun cl-user-program-version ()
    *program-version*)
    (setf *program-version* "New program version"))
    (defun cl-user-program-copyright ()
      *program-copyright*)
      (setf *program-copyright* "New program copyright"))






