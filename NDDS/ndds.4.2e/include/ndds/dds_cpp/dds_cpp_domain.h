/*
 * @(#)dds_cpp_domain.h    generated by: makeheader    Mon Dec  3 23:08:33 2007
 *
 *		built from:	domain.ifcxx
 */

#ifndef dds_cpp_domain_h
#define dds_cpp_domain_h


  #ifndef dds_c_domain_h
    #include "dds_c/dds_c_domain.h"
  #endif
  #ifndef dds_cpp_infrastructure_h
    #include "dds_cpp/dds_cpp_infrastructure.h"
  #endif
  #ifndef dds_cpp_topic_h
    #include "dds_cpp/dds_cpp_topic.h"
  #endif
  #ifndef dds_c_sqlfilter_h
    #include "dds_c/dds_c_sqlfilter.h"
  #endif
  #ifndef dds_cpp_publication_h
    #include "dds_cpp/dds_cpp_publication.h"
  #endif
  #ifndef dds_cpp_subscription_h
    #include "dds_cpp/dds_cpp_subscription.h"
  #endif
  #ifndef dds_cpp_flowcontroller_h
    #include "dds_cpp/dds_cpp_flowcontroller.h"
  #endif
  #ifndef dds_cpp_dll_h
    #include "dds_cpp/dds_cpp_dll.h"
  #endif

class DDSCPPDllExport DDSDomainParticipantListener : 
        public virtual DDSTopicListener,
        public virtual DDSPublisherListener, 
        public virtual DDSSubscriberListener
{

  public:

    virtual ~DDSDomainParticipantListener();
};

struct DDS_ParticipantBuiltinTopicData;

struct DDS_TopicBuiltinTopicData;

class DDSContentFilter;

class DDSCPPDllExport DDSDomainParticipant : public DDSEntity {

  // --- eXtension methods: ------------------------------------------
  public:
    /*e \dref_DomainParticipant_get_default_datawriter_qos
     */
    virtual DDS_ReturnCode_t get_default_datawriter_qos(
        DDS_DataWriterQos& qos)
        = 0;
    
    /*e \dref_DomainParticipant_set_default_datawriter_qos
     */
    virtual DDS_ReturnCode_t set_default_datawriter_qos(
        const DDS_DataWriterQos& qos)
        = 0;

    /*e \dref_DomainParticipant_get_default_datareader_qos
     */
    virtual DDS_ReturnCode_t get_default_datareader_qos(
        DDS_DataReaderQos& qos)
        = 0;
    
    /*e \dref_DomainParticipant_set_default_datareader_qos
     */
    virtual DDS_ReturnCode_t set_default_datareader_qos(
        const DDS_DataReaderQos& qos)
        = 0;

    /*e \dref_DomainParticipant_get_default_flowcontroller_property
     */
    virtual DDS_ReturnCode_t get_default_flowcontroller_property(
        DDS_FlowControllerProperty_t &property)
        = 0;

    /*e \dref_DomainParticipant_set_default_flowcontroller_property
     */
    virtual DDS_ReturnCode_t set_default_flowcontroller_property(
        const DDS_FlowControllerProperty_t &property)
        = 0;
    
    /*e \dref_DomainParticipant_register_contentfilter
     */
    virtual DDS_ReturnCode_t register_contentfilter(
	const char *filter_name,
	const DDSContentFilter *contentfilter) = 0;

    /*e \dref_DomainParticipant_lookup_contentfilter
     */
    virtual DDSContentFilter* lookup_contentfilter(
	const char *filter_name) = 0;

    /*e \dref_DomainParticipant_unregister_contentfilter
     */
    virtual DDS_ReturnCode_t unregister_contentfilter(
	const char *filter_name) = 0;
    
  // --- <<interface>> DDSDomainParticipant: --------------------------
  public:
    /*e \dref_DomainParticipant_get_default_topic_qos
     */
    virtual DDS_ReturnCode_t get_default_topic_qos(DDS_TopicQos& qos)
        = 0;
    
    /*e \dref_DomainParticipant_set_default_topic_qos
     */
    virtual DDS_ReturnCode_t set_default_topic_qos(
        const DDS_TopicQos& qos)
        = 0;
    
    /*e \dref_DomainParticipant_get_default_publisher_qos
     */
    virtual DDS_ReturnCode_t get_default_publisher_qos(DDS_PublisherQos& qos)
        = 0;

    /*e \dref_DomainParticipant_set_default_publisher_qos
     */
    virtual DDS_ReturnCode_t set_default_publisher_qos(
        const DDS_PublisherQos& qos)
        = 0;

    /*e \dref_DomainParticipant_get_default_subscriber_qos
     */
    virtual DDS_ReturnCode_t get_default_subscriber_qos(
        DDS_SubscriberQos& qos)
        = 0;
  
    /*e \dref_DomainParticipant_set_default_subscriber_qos
     */
    virtual DDS_ReturnCode_t set_default_subscriber_qos(
        const DDS_SubscriberQos& qos)
        = 0;

    /*e \dref_DomainParticipant_create_publisher
     */
    virtual DDSPublisher* create_publisher(
        const DDS_PublisherQos& qos,
        DDSPublisherListener* listener,
	DDS_StatusMask mask)
        = 0;

    /*e \dref_DomainParticipant_delete_publisher
     */
    virtual DDS_ReturnCode_t delete_publisher(DDSPublisher* p)
        = 0;

    /*e \dref_DomainParticipant_create_subscriber
     */
    virtual DDSSubscriber* create_subscriber(
	const DDS_SubscriberQos& qos,
	DDSSubscriberListener* listener,
	DDS_StatusMask mask)
        = 0;

    /*e \dref_DomainParticipant_delete_subscriber
     */
    virtual DDS_ReturnCode_t delete_subscriber(DDSSubscriber* s)
        = 0;

    /*e \dref_DomainParticipant_get_publishers
     */
    virtual DDS_ReturnCode_t get_publishers(DDSPublisherSeq& publishers)
        = 0;

    /*e \dref_DomainParticipant_get_subscribers
     */
    virtual DDS_ReturnCode_t get_subscribers(DDSSubscriberSeq& subscribers)
        = 0;

    /*e \dref_DomainParticipant_create_topic
     */
    virtual DDSTopic* create_topic(const char* topic_name, 
	const char* type_name,
        const DDS_TopicQos& qos,
	DDSTopicListener* listener,
	DDS_StatusMask mask)
        = 0;

    /*e \dref_DomainParticipant_delete_topic
     */
     virtual DDS_ReturnCode_t delete_topic(DDSTopic* topic)
        = 0;

    /*e \dref_DomainParticipant_create_contentfilteredtopic
     */
    virtual DDSContentFilteredTopic* create_contentfilteredtopic(
        const char* name, DDSTopic* related_topic,
        const char* filter_expression, 
        const DDS_StringSeq& expression_parameters) = 0;

    /*e \dref_DomainParticipant_create_contentfilteredtopic_with_filter
     */
    virtual DDSContentFilteredTopic* create_contentfilteredtopic_with_filter(
        const char* name, DDSTopic* related_topic,
        const char* filter_expression, 
        const DDS_StringSeq& expression_parameters,
	    const char* filter_name=DDS_SQLFILTER_NAME)
        = 0;

    /*e \dref_DomainParticipant_delete_contentfilteredtopic
     */
    virtual DDS_ReturnCode_t delete_contentfilteredtopic(
        DDSContentFilteredTopic* a_contentfilteredtopic)
        = 0;

    /*e \dref_DomainParticipant_create_multitopic
     */
    virtual DDSMultiTopic* create_multitopic(
        const char* name, const char* type_name, 
        const char* subscription_expression, 
        const DDS_StringSeq& expression_parameters)
        = 0;

    /*e \dref_DomainParticipant_delete_multitopic
    */
    virtual DDS_ReturnCode_t delete_multitopic(
        DDSMultiTopic* a_multitopic)
        = 0;

    /*e \dref_DomainParticipant_find_topic
     */
    /*i
      Deviates from Spec:timeout param is not used

      Note: The current implementation only looks up the \em
      locally created topics. The DDSTopic is a local object that acts 
      as a 'proxy' to designate the global concept of topic. 

      @pre If a DDSTopic of the same name already exists, it gives access
      to it, otherwise it waits (blocks the caller) until another
      mechanism creates it (or the specified \p timeout occurs). This
      other mechanism can be another thread, a configuration tool,
      or some other middleware service. 

      @return If the operation times-out, a NULL value is returned.	  
    */
    virtual DDSTopic* find_topic(
	const char* topic_name,
	const DDS_Duration_t& timeout)
        = 0;

    /*e  \dref_DomainParticipant_lookup_topicdescription
     */
    virtual DDSTopicDescription* lookup_topicdescription(
	const char* topic_name)
        = 0;

    /*e \dref_DomainParticipant_create_flowcontroller
     */
    virtual DDSFlowController *create_flowcontroller(
        const char *name,
        const DDS_FlowControllerProperty_t &property)
        = 0;

    /*e \dref_DomainParticipant_delete_flowcontroller
     */
    virtual DDS_ReturnCode_t delete_flowcontroller(
        DDSFlowController *fc)
        = 0;

    /*e \dref_DomainParticipant_lookup_flowcontroller
     */
    virtual DDSFlowController *lookup_flowcontroller(
        const char *name)
        = 0;
        
    /*e  \dref_DomainParticipant_get_builtin_subscriber
     */
    virtual DDSSubscriber* get_builtin_subscriber()
        = 0;

    /*e  \dref_DomainParticipant_ignore_participant
     */
    virtual DDS_ReturnCode_t ignore_participant(
        const DDS_InstanceHandle_t& handle) 
        = 0;
    
    /*e  \dref_DomainParticipant_ignore_topic
     */
    virtual DDS_ReturnCode_t ignore_topic(const DDS_InstanceHandle_t& handle) 
        = 0;
    
    /*e \dref_DomainParticipant_ignore_publication
     */
    virtual DDS_ReturnCode_t ignore_publication(
        const DDS_InstanceHandle_t& handle)
        = 0;

    /*e  \dref_DomainParticipant_ignore_subscription
     */
    virtual DDS_ReturnCode_t ignore_subscription(
        const DDS_InstanceHandle_t& handle)
        = 0;
    
    /*e  \dref_DomainParticipant_get_domain_id
     */
    virtual DDS_DomainId_t get_domain_id()
        = 0;

    /*e \dref_DomainParticipant_get_current_time
     */
    virtual DDS_ReturnCode_t get_current_time(DDS_Time_t& current_time)
        = 0;

    /*e \dref_DomainParticipant_assert_liveliness
    */
    virtual DDS_ReturnCode_t assert_liveliness()
        = 0;

    /*e \dref_DomainParticipant_delete_contained_entities
    */
    virtual DDS_ReturnCode_t delete_contained_entities()
	= 0;

    /*e \dref_DomainParticipant_get_discovered_participants
    */
    virtual DDS_ReturnCode_t get_discovered_participants(
        DDS_InstanceHandleSeq& participant_handles)
        = 0;

    /*e \dref_DomainParticipant_get_discovered_participant_data
    */
    virtual DDS_ReturnCode_t get_discovered_participant_data(
        struct DDS_ParticipantBuiltinTopicData& participant_data,
        const DDS_InstanceHandle_t& participant_handle)
        = 0;

    /*e \dref_DomainParticipant_get_discovered_topics
    */
    virtual DDS_ReturnCode_t get_discovered_topics(
        DDS_InstanceHandleSeq& topic_handles)
        = 0;

    /*e \dref_DomainParticipant_get_discovered_topic_data
    */
    virtual DDS_ReturnCode_t get_discovered_topic_data(
        struct DDS_TopicBuiltinTopicData& topic_data,
        const DDS_InstanceHandle_t& topic_handle)
        = 0;

    /*i \dref_DomainParticipant_get_publications
    */
    virtual DDS_ReturnCode_t get_publications(
        DDS_InstanceHandleSeq& publication_handles,
	DDS_Boolean include_contained_entities)
        = 0;

    /*i \dref_DomainParticipant_get_publication_data
    */
    virtual DDS_ReturnCode_t get_publication_data(
        struct DDS_PublicationBuiltinTopicData& publication_data,
        const DDS_InstanceHandle_t& publication_handle)
        = 0;

    /*i \dref_DomainParticipant_get_subscriptions
    */
    virtual DDS_ReturnCode_t get_subscriptions(
        DDS_InstanceHandleSeq& subscription_handles,
	DDS_Boolean include_contained_entities)
        = 0;

    /*i \dref_DomainParticipant_get_subscription_data
    */
    virtual DDS_ReturnCode_t get_subscription_data(
        struct DDS_SubscriptionBuiltinTopicData& subscription_data,
        const DDS_InstanceHandle_t& subscription_handle)
        = 0;

    /*e \dref_DomainParticipant_contains_entity
    */
    virtual DDS_Boolean contains_entity(const DDS_InstanceHandle_t& a_handle)
        = 0;


  // --- <<impl>> eXtensions: ------------------------------------------
  public:
  
    virtual DDS_DomainParticipant* get_c_domain_participantI()
	= 0;

    /*i \dref_DomainParticipant_start_databsase_interactive_shellI
    */
    virtual void start_database_interactive_shellI()
	= 0;

  // --- <<interface>> DDSEntity: --------------------------------------
  public:
  
    /*e \dref_DomainParticipant_set_qos
     */
    virtual DDS_ReturnCode_t set_qos(
        const DDS_DomainParticipantQos& qos)
        = 0;

    /*e \dref_DomainParticipant_get_qos
     */
    virtual DDS_ReturnCode_t get_qos(DDS_DomainParticipantQos& qos)
        = 0;

    /*e \dref_DomainParticipant_add_peer
     */
    virtual DDS_ReturnCode_t add_peer(const char* peer_desc_string) = 0;

    /*e \dref_DomainParticipant_set_listener
     */
    virtual DDS_ReturnCode_t set_listener(
                DDSDomainParticipantListener* l, 
		DDS_StatusMask mask = DDS_STATUS_MASK_ALL)
        = 0;

    /*e \dref_DomainParticipant_get_listener
     */
    virtual DDSDomainParticipantListener* get_listener()
        = 0;

  // --- <<lifecycle>>: ------------------------------------------------
  protected: 

    virtual ~DDSDomainParticipant();     
};

class DDSDomainParticipantFactory_impl;

class DDSCPPDllExport DDSDomainParticipantFactory {
  // --- <<conversion>>: -----------------------------------------------
  public: 
    /*i
      @brief Get the underlying implementation class object.	  
     */
    virtual DDSDomainParticipantFactory_impl* 
    			get_impl_DomainParticipantFactoryI() 
        = 0;

  // --- <<interface>> DDSDomainParticipantFactory ---------------------
  public: 
    /*e \dref_DomainParticipantFactory_get_instance
     */
    static DDSDomainParticipantFactory* get_instance();

    /*e \dref_DomainParticipantFactory_finalize_instance
     */
    static DDS_ReturnCode_t finalize_instance();

    /*e \dref_DomainParticipantFactory_set_default_participant_qos
     */
    virtual DDS_ReturnCode_t set_default_participant_qos(
	const DDS_DomainParticipantQos& qos)
	= 0;

    /*e \dref_DomainParticipantFactory_get_default_participant_qos
     */
    virtual DDS_ReturnCode_t get_default_participant_qos(
        DDS_DomainParticipantQos& qos)
        = 0;

    /*e \dref_DomainParticipantFactory_create_participant
     */
    virtual DDSDomainParticipant* create_participant(
        DDS_DomainId_t domainId, 
        const DDS_DomainParticipantQos& qos,
        DDSDomainParticipantListener* listener,
	DDS_StatusMask mask)
        = 0;

    /*e \dref_DomainParticipantFactory_delete_participant
     */
    virtual DDS_ReturnCode_t delete_participant(
        DDSDomainParticipant* a_participant)
        = 0;

    /*e \dref_DomainParticipantFactory_lookup_participant
     */
    virtual DDSDomainParticipant* lookup_participant(DDS_DomainId_t domainId)
        = 0;

  // --- <<eXtension>> methods: ---------------------------------------
  public: 
    /*e \dref_DomainParticipantFactory_set_qos
     */
    virtual DDS_ReturnCode_t set_qos(
        const DDS_DomainParticipantFactoryQos& qos)
        = 0;

    /*e \dref_DomainParticipantFactory_get_qos
     */
    virtual DDS_ReturnCode_t get_qos(DDS_DomainParticipantFactoryQos& qos)
        = 0;
        
  // --- <<lifecycle>>: ------------------------------------------------
  protected:

    virtual ~DDSDomainParticipantFactory(); // force use destroy_instanceX()

  // --- The <<singleton>> instance: ----------------------------------
  private:
    /*i
      @brief \st_singleton The singleton instance.	  
     */
    static DDSDomainParticipantFactory_impl* _instance; 
};


#define DDSTheParticipantFactory DDSDomainParticipantFactory::get_instance()

#endif /* dds_cpp_domain_h */