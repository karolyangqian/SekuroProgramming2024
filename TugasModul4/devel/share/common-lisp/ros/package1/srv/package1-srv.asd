
(cl:in-package :asdf)

(defsystem "package1-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "magnitude" :depends-on ("_package_magnitude"))
    (:file "_package_magnitude" :depends-on ("_package"))
  ))