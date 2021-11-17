
(cl:in-package :asdf)

(defsystem "capstone-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "Pose" :depends-on ("_package_Pose"))
    (:file "_package_Pose" :depends-on ("_package"))
    (:file "Position" :depends-on ("_package_Position"))
    (:file "_package_Position" :depends-on ("_package"))
    (:file "Rotation" :depends-on ("_package_Rotation"))
    (:file "_package_Rotation" :depends-on ("_package"))
  ))