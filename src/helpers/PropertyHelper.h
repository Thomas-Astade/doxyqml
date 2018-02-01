#ifndef _PROPERTY_HELPER_H_
#define _PROPERTY_HELPER_H_


#include <QObject>

#define WRITABLE_PROPERTY_EXTRA_ON_SET(type, name, extra) \
    protected: \
        /**@brief A property, defined by the macro WRITABLE_PROPERTY_EXTRA_ON_SET*/ \
        Q_PROPERTY (type name READ get_##name WRITE set_##name NOTIFY name##Changed) \
    protected: \
        /**@brief The member variable to implement the property "name" */ \
        type m_##name; \
    public: \
        /**@brief The accessor to the property "name" */ \
        type get_##name (void) const { \
            return m_##name ; \
        } \
    public Q_SLOTS: \
        /**@brief The mutator of the property "name" */ \
        bool set_##name (type name) { \
            bool ret = false; \
            if ((ret = (m_##name != name))) { \
                m_##name = name; \
                emit name##Changed (m_##name); \
            } \
            extra; \
            return ret; \
        } \
    Q_SIGNALS: \
        /**@brief The signal notifies a change of the property */ \
        void name##Changed (type name); \
    private:

#define WRITABLE_PROPERTY_EXTRA_ON_SET_DOCUMENTED(type, name, extra, comment) \
    protected: \
        /**@brief comment*/ \
        Q_PROPERTY (type name READ get_##name WRITE set_##name NOTIFY name##Changed) \
    protected: \
        /**@brief The member variable to implement the property "name"*/ \
        type m_##name; \
    public: \
        /**@brief The accessor to the property "name"*/ \
        type get_##name (void) const { \
            return m_##name ; \
        } \
    public Q_SLOTS: \
        /**@brief The mutator of the property "name"*/ \
        bool set_##name (type name) { \
            bool ret = false; \
            if ((ret = (m_##name != name))) { \
                m_##name = name; \
                emit name##Changed (m_##name); \
            } \
            extra; \
            return ret; \
        } \
    Q_SIGNALS: \
        /**@brief The signal notifies a change of the property "name"*/ \
        void name##Changed (type name); \
    private:

#define WRITABLE_PROPERTY_EXTRA_ON_CHANGE(type, name, extra) \
    protected: \
        /**@brief A property, defined by the macro WRITABLE_PROPERTY_EXTRA_ON_CHANGE*/ \
        Q_PROPERTY (type name READ get_##name WRITE set_##name NOTIFY name##Changed) \
    protected: \
        /**@brief The member variable to implement the property "name" */ \
        type m_##name; \
    public: \
        /**@brief The accessor to the property "name" */ \
        type get_##name (void) const { \
            return m_##name ; \
        } \
    public Q_SLOTS: \
        /**@brief The mutator of the property "name" */ \
        bool set_##name (type name) { \
            bool ret = false; \
            if ((ret = (m_##name != name))) { \
                m_##name = name; \
                extra; \
                emit name##Changed (m_##name); \
            } \
            return ret; \
        } \
    Q_SIGNALS: \
        /**@brief The signal notifies a change of the property "name" */ \
        void name##Changed (type name); \
    private:

#define WRITABLE_PROPERTY_EXTRA_ON_CHANGE_DOCUMENTED(type, name, extra, comment) \
    protected: \
        /**@brief comment*/ \
        Q_PROPERTY (type name READ get_##name WRITE set_##name NOTIFY name##Changed) \
    protected: \
        /**@brief the member variable to implement the property "name" */ \
        type m_##name; \
    public: \
        /**@brief The accessor to the property "name" */ \
        type get_##name (void) const { \
            return m_##name ; \
        } \
    public Q_SLOTS: \
        /**@brief The mutator of the property "name" */ \
        bool set_##name (type name) { \
            bool ret = false; \
            if ((ret = (m_##name != name))) { \
                m_##name = name; \
                extra; \
                emit name##Changed (m_##name); \
            } \
            return ret; \
        } \
    Q_SIGNALS: \
        /**@brief The signal notifies a change of the property "name"*/ \
        void name##Changed (type name); \
    private:

#define WRITABLE_PROPERTY(type, name) \
    protected: \
        /**@brief A property, defined by the macro WRITABLE_PROPERTY*/ \
        Q_PROPERTY (type name READ get_##name WRITE set_##name NOTIFY name##Changed) \
    protected: \
        /**@brief the member variable to implement the property "name" */ \
        type m_##name; \
    public: \
        /**@brief The accessor to the property "name" */ \
        type get_##name (void) const { \
            return m_##name ; \
        } \
    public Q_SLOTS: \
        /**@brief The mutator of the property "name" */ \
        bool set_##name (type name) { \
            bool ret = false; \
            if ((ret = (m_##name != name))) { \
                m_##name = name; \
                emit name##Changed (m_##name); \
            } \
            return ret; \
        } \
    Q_SIGNALS: \
        /**@brief The signal notifies a change of the property "name" */ \
        void name##Changed (type name); \
    private:

#define WRITABLE_PROPERTY_DOCUMENTED(type, name, comment) \
    protected: \
        /**@brief comment*/ \
        Q_PROPERTY (type name READ get_##name WRITE set_##name NOTIFY name##Changed) \
    protected: \
        /**@brief the member variable to implement the property "name" */ \
        type m_##name; \
    public: \
        /**@brief The accessor to the property "name" */ \
        type get_##name (void) const { \
            return m_##name ; \
        } \
    public Q_SLOTS: \
        /**@brief The mutator of the property "name" */ \
        bool set_##name (type name) { \
            bool ret = false; \
            if ((ret = (m_##name != name))) { \
                m_##name = name; \
                emit name##Changed (m_##name); \
            } \
            return ret; \
        } \
    Q_SIGNALS: \
        /**@brief The signal notifies a change of the property "name" */ \
        void name##Changed (type name); \
    private:

#define READONLY_PROPERTY(type, name) \
    protected: \
        /**@brief A property, defined by the macro WRITABLE_PROPERTY*/ \
        Q_PROPERTY (type name READ get_##name NOTIFY name##Changed) \
    protected: \
        /**@brief The member variable to implement the property "name" */ \
        type m_##name; \
    public: \
        /**@brief The accessor to the property "name" */ \
        type get_##name (void) const { \
            return m_##name ; \
        } \
    public Q_SLOTS: \
        /**@brief The mutator of the property "name" */ \
        bool set_##name (type name) { \
            bool ret = false; \
            if ((ret = (m_##name != name))) { \
                m_##name = name; \
                emit name##Changed (m_##name); \
            } \
            return ret; \
        } \
    Q_SIGNALS: \
        /**@brief The signal notifies a change of the property "name" */ \
        void name##Changed (type name); \
    private:

#endif
